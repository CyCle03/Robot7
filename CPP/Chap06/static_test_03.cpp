#include <iostream>
using namespace std;

class PersonError
{
private:
    int money;
    static inline int staticMoney = 0;
public:
    // static int getMoney()
    // {
    //     return money; // Error: cannot access non-static member 'money' from a static context
    // }
    static int getStaticMoney()
    {
        //this->staticMoney; // Error: cannot use 'this' pointer in a static member function
        return staticMoney; // Correct: accessing static member 'staticMoney'
    }
    void setMoney(int money)
    {
        this->money = money; // Correct: accessing non-static member 'money' through 'this' pointer
        staticMoney += money; // Correct: accessing static member 'staticMoney'
    }
    int getMoney()
    {
        return money; // Correct: accessing non-static member 'money'
    }
};

int main()
{
    int n = PersonError::getStaticMoney();

    PersonError pr;
    pr.setMoney(10000);
    cout << "Money: " << pr.getMoney() << endl;

    return 0;
}
