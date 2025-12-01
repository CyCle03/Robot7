#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
using namespace std;

class Account
{
  private:
    int id;
    string name;
    int balance;
public:
    Account(int id, const string& name, int balance)
    {
        this->id = id;
        this->name = name;
        this->balance = balance;
    }
    int getId() const { return id; }
    string getName() const { return name; }
    int getBalance() const { return balance; }
    void deposit(int amount) 
    {
        if (amount > 0) 
        {
            balance += amount;
            cout << amount << "원 입금되었습니다. 현재 잔액: " << balance << "원" << endl;
        } 
        else 
        {
            cout << "입금 금액은 양수여야 합니다." << endl;
        }
    }
    bool withdraw(int amount) 
    {
        if (amount > 0 && amount <= balance) 
        {
            balance -= amount;
            cout << amount << "원 출금되었습니다. 현재 잔액: " << balance << "원" << endl;
            return true;
        } 
        else 
        {
            cout << "출금 실패: 잔액이 부족하거나 잘못된 금액입니다." << endl;
            return false;
        }
    }
    void printInfo() const 
    {
        cout << "계좌 ID: " << id << ", 이름: " << name << ", 잔액: " << balance << "원" << endl;
    }
};

int main() 
{

    // 1. 계좌 생성
    Account acc1(1001, "홍길동", 50000);
    Account acc2(1002, "이순신", 30000);

    // 2. 입금/출금 테스트
    acc1.deposit(20000);    // 정상 입금
    acc2.withdraw(5000);    // 정상 출금
    acc2.withdraw(50000);   // 실패 테스트 (잔액 부족)

    // 3. 계좌 정보 출력
    acc1.printInfo();
    acc2.printInfo();

    // 4. vector로 여러 계좌 관리
    vector<Account> v;
    v.push_back(acc1);
    v.push_back(acc2);

    cout << endl <<"=== 전체 계좌 목록 ===" << endl;
    for (const auto& acc : v) 
    {
        acc.printInfo();
    }

    return 0;
}
