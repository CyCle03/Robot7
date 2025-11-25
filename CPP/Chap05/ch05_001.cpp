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
public:
    void playA()
    {
        cout << "playA() 동작함." << endl;
    }
};

int main()
{
    Unicorn mary;

    mary.run();
    mary.fly();
    mary.playA();

    return 0;
}
