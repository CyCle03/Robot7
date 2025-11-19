#include <iostream>
#include <string>

class Circle
{
public:
    //1. 멤버 변수
    int radius;
    std::string color;
    //2. 생성자
    Circle():radius(1), color("WHITE")//초기화 변수
    {
        std::cout << "반지름이 " << this->radius << ", 색상이 " << color << "인 원 생성" << std::endl;
    }

    Circle(int r):radius(r), color("WHITE")
    {
        std::cout << "반지름이 " << this->radius <<  ", 색상이 " << color << "인 원 생성" << std::endl;
    }

    Circle(int r, std::string c):radius(r), color(c)
    {
        std::cout << "반지름이 " << this->radius << ", 색이 " << c << "인 원 생성" << std::endl;
    }

    double getArea()
    {
        return 3.14*radius*radius;
    }
    //3. 멤버 메소드
};

int main()
{
    using namespace std;

    Circle donut;
    Circle pizza(30);
    Circle tire(10, "RED");

    return 0;
}
