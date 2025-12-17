import re
import pandas as pd
from datetime import datetime
import glob
import gzip
import os

# ====================================================================
# 1. 정규 표현식 정의
# ====================================================================

# Syslog ISO 8601 타임스탬프 형식 대응
SYSLOG_REGEX = re.compile(
    r"^(?P<timestamp>[\d\-]+T[\d\:\.]+[\+\-]\d{2}:\d{2})"
    r"\s+(?P<hostname>[\w\-\.]+)"
    r"\s+(?P<process>[\w\-\.]+)(?:\[(?P<pid>\d+)\])?:?"
    r"\s*(?P<message>.*)$"
)

# Auth Log에서 SSH 로그인 실패를 파싱하기 위한 정규 표현식
AUTH_FAIL_REGEX = re.compile(
    # 'Failed password for userX from 1.2.3.4 port 1234 ssh2' 형식 파싱
    r".*Failed password for (?:invalid user )?(?P<user>\w+)\s+from\s+(?P<ip>\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})\s+port"
)


# ====================================================================
# 2. 범용 로그 파서 및 파일 리더 함수
# ====================================================================

def parse_log_line(line, regex):
    """단일 로그 라인을 주어진 정규식으로 파싱하여 딕셔너리로 반환"""
    if isinstance(line, bytes):
        try:
            line = line.decode('utf-8')
        except UnicodeDecodeError:
            return None
            
    match = regex.match(line.strip())
    if match:
        return match.groupdict()
    return None

def read_and_parse_log_files(file_path_pattern, regex):
    """
    지정된 패턴과 일치하는 모든 로그 파일(일반, 압축)을 읽고 파싱
    (gz 파일 처리 오류, 인코딩 오류 수정 완료)
    """
    
    log_files = glob.glob(file_path_pattern)
    log_files.sort(key=os.path.getmtime, reverse=True)
    
    parsed_data = []
    
    print(f"[정보] 총 {len(log_files)}개의 로그 파일을 분석합니다.")
    
    for file_path in log_files:
        print(f"  > 파일 분석 중: {file_path}")
        
        # 압축 파일 (.gz) 처리: 바이너리 모드(rb) 사용, encoding/errors 인수 제거
        if file_path.endswith('.gz'):
            opener = gzip.open
            mode = 'rb' 
            encoding_args = {} 
        # 일반 파일 처리: 텍스트 모드(r) 사용, encoding/errors 인수 사용
        else:
            opener = open
            mode = 'r' 
            encoding_args = {'encoding': 'utf-8', 'errors': 'ignore'} 
            
        try:
            with opener(file_path, mode, **encoding_args) as f:
                for line in f:
                    data = parse_log_line(line, regex)
                    if data:
                        parsed_data.append(data)
        except Exception as e:
            print(f"[경고] 파일 '{file_path}' 처리 중 오류 발생: {e}")
            
    return parsed_data


# ====================================================================
# 3. 분석 및 집계 함수
# ====================================================================

def analyze_syslog(file_path_pattern, df):
    """Syslog (시스템 이벤트) 로그를 분석하고 결과를 출력"""
    
    if df.empty:
        print("\n[알림] Syslog 데이터가 없습니다.")
        return
    
    print("-" * 50)
    print(f"로그 분석 결과: {file_path_pattern} 패턴")
    print(f"총 분석된 유효 로그 라인 수: {len(df)}개")
    print("-" * 50)

    # A. 가장 빈번한 프로세스 TOP 5
    print("\n[A] 가장 빈번한 프로세스/데몬 (TOP 5)")
    print(df['process'].value_counts().head(5).to_markdown())
    
    # B. 의심되는 오류 메시지 (Error/Fail/Fatal) 상세 분석
    error_logs = df[df['message'].str.contains('error|fail|fatal', case=False, na=False)]
    
    print(f"\n[B] 의심되는 오류/실패 메시지 총 개수: {len(error_logs)} 건")
    
    if not error_logs.empty:
        # 오류 발생 프로세스 TOP 5
        print("\n   - 오류 발생 프로세스 (TOP 5):")
        error_process_counts = error_logs['process'].value_counts().head(5)
        print(error_process_counts.to_markdown())
        
        # 상위 5개 오류 메시지 상세
        print("\n   - 상위 5개 오류 메시지 상세:")
        print(error_logs[['timestamp', 'process', 'message']].head(5).to_markdown(index=False))

    
    # C. 시간대별 이벤트 분포
    df['hour'] = df['timestamp'].dt.hour
    hourly_distribution = df['hour'].value_counts().sort_index()
    print("\n[C] 시간대별 로그 발생 분포")
    print(hourly_distribution.to_markdown())
    
    print("-" * 50)


def analyze_auth_log(file_path_pattern):
    """Auth Log (인증/보안 이벤트) 로그를 분석하고 결과를 출력"""
    
    parsed_auth_data = read_and_parse_log_files(file_path_pattern, SYSLOG_REGEX)
    
    if not parsed_auth_data:
        print("\n[알림] Auth Log 데이터가 없습니다.")
        return

    df_auth = pd.DataFrame(parsed_auth_data)
    
    print("\n" + "=" * 50)
    print(f"Linux 인증 로그 요약 ({file_path_pattern} 패턴)")
    print("=" * 50)
    print(f"총 분석된 인증 로그 라인 수: {len(df_auth)}개")

    # 1. 인증 실패 필터링 및 IP 추출
    failed_attempts = df_auth[df_auth['message'].str.contains('Failed password', case=False, na=False)].copy()
    
    # 메시지에서 IP와 사용자 추출
    extracted = failed_attempts['message'].str.extract(AUTH_FAIL_REGEX)
    failed_attempts['source_ip'] = extracted['ip']
    
    total_failed = len(failed_attempts.dropna(subset=['source_ip']))
    print(f"인증 실패 메시지 총 개수: {total_failed} 건")
    
    if total_failed > 0:
        top_failed_ips = failed_attempts['source_ip'].value_counts().head(5)
        print("\n인증 실패 상위 IP (TOP 5):")
        print(top_failed_ips.reset_index().rename(columns={'index': 'IP 주소', 'source_ip': '시도 횟수'}).to_markdown(index=False))
        
    print("-" * 50)

# ====================================================================
# 4. 시각화 및 타임라인 분석 함수
# ====================================================================

def get_severity(message):
    """메시지 내용에 따라 심각도 라벨을 반환"""
    message = message.lower()
    if 'error' in message or 'fatal' in message or 'fail' in message:
        return '[ERROR]'
    elif 'warn' in message or 'warning' in message or 'unstable' in message or 'throttle' in message:
        return '[WARN ]'
    else:
        return '[INFO ]'

def print_summary(df_syslog, hours=6):
    """최근 hours 시간 동안의 핵심 이상 징후를 요약"""
    
    # 1. 최근 시간 필터링
    end_time = df_syslog['timestamp'].max()
    start_time = end_time - pd.Timedelta(hours=hours)
    df_recent = df_syslog[(df_syslog['timestamp'] >= start_time)]

    if df_recent.empty:
        print(f"\n[알림] 최근 {hours}시간 동안의 로그 데이터가 없습니다.")
        return

    # 2. 이벤트 분류 및 카운트
    events = {
        '서비스 재시작': df_recent['message'].str.contains('restarted|stopping|starting', case=False).sum(),
        '장치 연결/해제': df_recent['message'].str.contains('usb|disconnect|reset', case=False).sum(),
        '네트워크 단절': df_recent['message'].str.contains('link down|failed|checkconnection', case=False).sum(),
        '커널 경고': df_recent['message'].str.contains('WARN|Fatal|throttle', case=False).sum(),
    }
    
    # 상세 이벤트 (예시)
    restart_details = df_recent[df_recent['message'].str.contains('restarted', case=False)]
    
    print("\n" + "=" * 50)
    print(f"시스템 이상 징후 요약 (syslog)")
    print("=" * 50)
    print(f"분석 대상 : {SYSLOG_PATTERN}")
    print(f"기간      : {hours}시간 이내 ({start_time.strftime('%H:%M')} ~ {end_time.strftime('%H:%M')})")
    print("-" * 50)
    
    print("\n[중요 이벤트]")
    for event, count in events.items():
        print(f"- {event:18} : {count}건")
    
    if restart_details.empty is False:
        print("\n서비스 재시작 상세 (TOP 3)")
        restarted_processes = restart_details['process'].value_counts().head(3)
        for proc, count in restarted_processes.items():
            print(f"- {proc}: {count}회")
            
    print("=" * 50)


def print_timeline(df_syslog, hours_ago=1):
    """특정 시간 동안의 로그를 타임라인으로 출력"""
    
    end_time = df_syslog['timestamp'].max()
    start_time = end_time - pd.Timedelta(hours=hours_ago)
    df_timeline = df_syslog[(df_syslog['timestamp'] >= start_time)].copy()

    if df_timeline.empty:
        print(f"\n[알림] 최근 {hours_ago}시간 동안의 타임라인 로그가 없습니다.")
        return

    df_timeline['severity'] = df_timeline['message'].apply(get_severity)
    df_timeline['time_str'] = df_timeline['timestamp'].dt.strftime('%H:%M')
    
    print("\n" + "=" * 50)
    print(f"시스템 이벤트 타임라인 (syslog)")
    print("=" * 50)
    print(f"분석 파일 : {SYSLOG_PATTERN}")
    print(f"기간      : {start_time.strftime('%Y-%m-%d %H:%M')} ~ {end_time.strftime('%Y-%m-%d %H:%M')}")
    print("-" * 50)
    
    print("상위 10개 이벤트:")
    # 시간순으로 출력
    for index, row in df_timeline.sort_values(by='timestamp').head(10).iterrows():
        # 메시지 길이를 80자로 제한
        msg = row['message']
        if len(msg) > 80:
            msg = msg[:77] + '...'
            
        print(f"{row['time_str']}  {row['severity']} {row['process']:12} - {msg}")
    
    print("...")
    print("=" * 50)


# ====================================================================
# 5. 분석기 실행
# ====================================================================

# Syslog 패턴: /var/log/syslog와 모든 로테이션 파일
SYSLOG_PATTERN = '/var/log/syslog*' 
# Auth Log 패턴: /var/log/auth.log와 모든 로테이션 파일
AUTH_LOG_PATTERN = '/var/log/auth.log*' 

if __name__ == '__main__':
    
    # try-except 블록 내에서 DataFrame을 생성하여 재사용
    try:
        # 1. Syslog 데이터 로드 및 전처리
        print("[정보] Syslog 데이터 로딩 및 분석 시작...")
        parsed_syslog_data = read_and_parse_log_files(SYSLOG_PATTERN, SYSLOG_REGEX)
        
        if parsed_syslog_data:
            df_syslog = pd.DataFrame(parsed_syslog_data)
            df_syslog['timestamp'] = pd.to_datetime(df_syslog['timestamp'], errors='coerce')
            df_syslog = df_syslog.dropna(subset=['timestamp']) 
            
            # --- Syslog 분석 실행: df_syslog를 전달합니다. ---
            analyze_syslog(SYSLOG_PATTERN, df_syslog)
            
            # --- 요약 및 타임라인 출력 ---
            print_summary(df_syslog, hours=6) 
            print_timeline(df_syslog, hours_ago=1)
        else:
            print(f"[알림] 분석할 Syslog 데이터가 없습니다: {SYSLOG_PATTERN}")

        # 2. Auth Log 분석 실행 (함수 내부에서 파일을 직접 읽습니다.)
        analyze_auth_log(AUTH_LOG_PATTERN)
        
    except PermissionError:
        print("\n[실행 오류] 로그 파일에 접근 권한이 없습니다. sudo를 사용하거나 파일을 복사하세요.")
    except Exception as e:
        print(f"\n[치명적 오류] 실행 중 예기치 않은 오류 발생: {e}")
