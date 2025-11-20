#include <iostream>

using namespace std;

class Car
{
public:
    //1. 멤버변수
    int speed;
    string brand;
    string color;
    //2. 생성자
    Car():speed(50), brand("Kia"), color("Red") //default 생성자. 생성자가 하나도 없으면 컴파일러가 자동으로 생성
    {}
    //3. 멤버메소드
    string run()
    {
        return "달리다!";
    }
};

int main()
{
    Car myCar;
    cout << "myCar.speed : " << myCar.speed << endl;
    cout << "myCar.brand : " << myCar.brand << endl;
    cout << "myCar.color : " << myCar.color << endl;
    cout << "run : " << myCar.run() << endl;

    return 0;
}
