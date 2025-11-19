#include <iostream>

class Circle
{
public:
    int radius;

    double getArea()//생성자
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
    area = pizza.getArea();
    cout << "pizza 면적은 " << area << endl;

    return 0;
}
