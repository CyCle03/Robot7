//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<time.h>
//
//int main()
//{
//	int current_year, birth_year, age_year;
//
//    time_t timer;      // 현재 시간을 초 단위로 저장할 변수
//    struct tm* t_info; // 날짜와 시간 정보를 저장할 구조체 포인터
//
//    // 1. 현재 시각(초)을 가져옴
//    timer = time(NULL);
//
//    // 2. 초 시간을 지역 시간(Local Time) 구조체로 변환
//    t_info = localtime(&timer);
//
//    // 3. struct tm 구조체의 tm_year 멤버를 사용해 현재 연도를 계산
//    // tm_year는 1900년 이후의 연도를 나타내므로 1900을 더해야 합니다.
//    current_year = t_info->tm_year + 1900;
//
//	printf("태어난 년도를 입력하세요.: ");
//
//	scanf("%d", &birth_year);
//
//    age_year = current_year - birth_year;
//
//    printf("나이는 생일이 지났다면 %d살, 지나지 않았다면 %d살 입니다.", age_year, age_year - 1);
//
//
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main()
{
    int current_year, birth_year;
    int age_year;

    // 현재 시간을 초 단위로 저장할 변수 및 구조체 포인터
    time_t timer;
    struct tm* t_info;

    // 1. 현재 시각(초)을 가져옴
    timer = time(NULL);

    // 2. 초 시간을 지역 시간(Local Time) 구조체로 변환
    t_info = localtime(&timer);

    // 3. struct tm 구조체의 tm_year 멤버를 사용해 현재 연도를 계산
    // 현재는 2025년입니다.
    current_year = t_info->tm_year + 1900;

    printf("태어난 년도를 입력하세요.: ");

    // 4. scanf에서 불필요한 '\n'을 제거하여 입력 오류를 방지
    scanf("%d", &birth_year);

    // 5. 나이 계산 (만 나이가 아닌 연 나이)
    age_year = current_year - birth_year;

    printf("\n[나이 계산 결과]\n");
    printf("현재 연도: %d년\n", current_year);
    printf("태어난 연도: %d년\n", birth_year);
    printf("만 나이: 생일이 지났다면 %d살, 지나지 않았다면 %d살 입니다.\n", age_year, age_year - 1);
    printf("연 나이 (한국식 나이): %d살 입니다.\n", age_year + 1);


    return 0;
}