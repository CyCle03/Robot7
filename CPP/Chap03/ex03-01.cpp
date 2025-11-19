#include <iostream>

class Circle
{
public:
    int radius;
    //생성자
    //없으면 컴파일러가 컴파일 시 자동으로 생성
    double getArea()
    {
        return 3.14*radius*radius;
    }
};

// double Circle::getArea()
// {
//     return 3.14*radius*radius;
// }

int main()
{
    using namespace std;

    Circle donut;//stack에 객체가 만들어집니다.
    donut.radius = 1;
    double area = donut.getArea();
    cout << "donut 면적은 " << area << endl;

    Circle pizza;
    pizza.radius = 30;
    cout << "pizza 면적은 " << pizza.getArea() << endl;

    return 0;
}
