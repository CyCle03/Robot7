#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// SRP(단일 책임 원칙)를 위반한 UserInfo 예제
// - 사용자 정보
// - 서버 정보 출력
// - 관리자 정보 저장
//   책임을 한 클래스에 모두 몰아넣음
class UserInfo {
private:
    // 사용자 정보
    string userName;
    string userEmail;

    // 서버 정보
    string serverIp;
    int    serverPort;

    // 관리자 정보
    string adminName;
    string adminEmail;

public:
    UserInfo(const string& userName,
             const string& userEmail,
             const string& serverIp,
             int serverPort)
        : userName(userName),
          userEmail(userEmail),
          serverIp(serverIp),
          serverPort(serverPort))
    {}

    // ① 사용자 정보 출력 책임
    void printUserInfo() const {
        cout << "[User] 이름: " << userName
             << ", 이메일: " << userEmail << endl;
    }

    // ② 서버 정보 출력 책임 (SRP 위반: UserInfo가 서버 출력까지 담당)
    void printServerInfo() const {
        cout << "[Server] IP: " << serverIp
             << ", Port: " << serverPort << endl;
    }
};

int main() {
    cout << "===== Bad Example (SRP 위반) =====" << endl;

    UserInfo user(
        "홍길동", "hong@example.com",
        "192.168.0.10", 8080
    );

    // UserInfo가 너무 많은 일을 하고 있음
    user.printUserInfo();
    user.printServerInfo();              // 서버 정보 출력도 UserInfo가 담당

    return 0;
}
