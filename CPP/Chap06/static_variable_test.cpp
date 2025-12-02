#include <iostream>

using namespace std;

class Person
{
public:
    int money;
    void addMoney(int money)
    {
        this->money += money;
    }
    static int sharedMoney;
    static void addShared(int n)
    {
        sharedMoney += n;
    }

    Person()
    {
        money = 10000;
        money++;
        sharedMoney++;
    }
};

int Person::sharedMoney = 10000;

int main()
{
    Person p1;
    cout << "p1 money: " << p1.money << endl;
    cout << "shared money: " << Person::sharedMoney << endl;

    Person p2;
    cout << "p2 money: " << p2.money << endl;
    cout << "shared money: " << Person::sharedMoney << endl;

    return 0;
}
