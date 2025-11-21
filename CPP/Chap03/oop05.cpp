#include <iostream>
using namespace std;

class Circle
{
public:
    int radius;
    double getArea()
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    Circle donut;
    cout << "donut의 넓이 : " << donut.getArea() << endl;

    Circle* p;
    p = &donut;
    cout << "p의 넓이 : " << p->getArea() << endl;
    cout << "p의 넓이 : " << (*p).getArea() << endl;

    Circle* donut2 = new Circle();
    cout << "donut2 넓이 : " << donut2->getArea() << endl;

    return 0;
}
