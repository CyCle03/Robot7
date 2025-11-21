#include <iostream>
using namespace std;

class Car
{
public:
    int speed;
    string brand;

    virtual void run()
    {
        cout << "차가 달린다." << endl;
    }
};

class SuperCar : public Car
{
public:
    int booster;
    SuperCar()
    {
        booster = 100;
    }

    void run() override
    {
        cout << "부스터 용량 : " << booster << " 차가 달린다." << endl;
    }
};

int main()
{
    Car car;
    car.run();

    SuperCar car2;
    car2.run();

    return 0;
}
