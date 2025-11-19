#include <iostream>
#include <string>

class Circle
{
public:
    //1. 멤버 변수
    int radius;
    //2. 생성자
    Circle():radius(1)//초기화 변수
    {
        std::cout << "반지름이 " << this->radius << "인 원 생성" << std::endl;
    }
    Circle(int r):radius(r)
    {
        std::cout << "반지름이 " << this->radius << "인 원 생성" << std::endl;
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

    return 0;
}
