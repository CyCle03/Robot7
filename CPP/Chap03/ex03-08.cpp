#include <iostream>
using namespace std;

class Car
{
private:
    int speed;

public:
    //Setter
    void setSpeed(int _speed)
    {
        speed = _speed;
    }
    //Getter
    int getSpeed()
    {
        return speed;
    }
};

int main()
{
    Car myCar;
    //myCar.speed = 100;//직접 접근
    myCar.setSpeed(100);//간접 접근
    //int speed = myCar.speed;//직접 접근
    int mySpeed = myCar.getSpeed();//간접 접근

    cout << "현재 차의 스피드는 : " << myCar.getSpeed() << endl;
    //cout << "현재 차의 스피드는 : " << mySpeed << endl;

    return 0;
}
