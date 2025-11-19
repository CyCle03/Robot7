#include <iostream>
#include <string>

class Circle
{
public:
    //1. 멤버 변수
    int radius;
    std::string color;
    //2. 생성자
    Circle()    //default 생성자
    {
        this->radius = 1;
        std::cout << "반지름이 " << this->radius << "인 원 생성" << std::endl;
    }
    Circle(int r)
    {
        this->radius = r;
        std::cout << "반지름이 " << this->radius << "인 원 생성" << std::endl;
    }
    Circle(int r, std::string c)
    {
        this->radius = r;
        color = c;
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
    Circle tire(10, "Red");

    return 0;
}
