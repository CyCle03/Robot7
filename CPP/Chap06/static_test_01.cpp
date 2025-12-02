#include <iostream>
using namespace std;

class Person
{
public:
    int money = 0;
    static inline int sharedMoney = 10;

    void addMoney(int money)
    {
        this->money += money;
    }
    static void addShared(int n)
    {
        sharedMoney += n;
    }
};

int main()
{
    Person han;
    han.money = 100;
    han.sharedMoney = 200;

    Person lee;
    lee.money = 150;
    lee.addMoney(200);
    lee.addShared(200);

    cout << han.money << ' ' << lee.money << endl;
    cout << han.sharedMoney << ' ' << lee.sharedMoney << endl;

    return 0;
}
