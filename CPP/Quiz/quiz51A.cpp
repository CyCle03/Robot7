#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class UserInfo {
private:
    // 사용자 정보
    string userName;
    string userEmail;

public:
    UserInfo(const string& userName,
             const string& userEmail)
        : userName(userName),
          userEmail(userEmail)
    {}

    // ① 사용자 정보 출력 책임
    void printUserInfo() const {
        cout << "[User] 이름: " << userName
             << ", 이메일: " << userEmail << endl;
    }
};

class ServerInfo
{
private:
    // 서버 정보
    string serverIp;
    int    serverPort;
public:
    ServerInfo(const string& serverIp,
             int serverPort)
             :serverIp(serverIp),
             serverPort(serverPort)
             {}
    // ② 서버 정보 출력 책임
    void printServerInfo() const 
    {
        cout << "[Server] IP: " << serverIp
             << ", Port: " << serverPort << endl;
    }
};



int main() {
    cout << "===== Good Example (SRP 원칙) =====" << endl;

    UserInfo user("홍길동", "hong@example.com");
    ServerInfo server("192.168.0.10", 8080);

    user.printUserInfo();
    server.printServerInfo();

    return 0;
}
