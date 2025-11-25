#include <iostream>
using namespace std;

class Horse
{
public:
    void run()
    {
        cout << "달리다." << endl;
    }
};

class Bird
{
public:
    void fly()
    {
        cout << "날다." << endl;
    }
};

class Unicorn : public Horse, public Bird
{

};

class Warrior
{
public:
    void attack()
    {
        cout << "공격하다." << endl;
    }
};

class Centaurus : public Horse, public Warrior
{

};

int main()
{
    Unicorn pony;

    pony.fly();
    pony.run();

    Centaurus cheiron;

    cheiron.run();
    cheiron.attack();

    return 0;
}
