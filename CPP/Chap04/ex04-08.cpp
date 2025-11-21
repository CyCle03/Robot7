#include <iostream>
using namespace std;

class Circle
{
private:
    int radius;
public:
    Circle()
    {
        radius = 1;
        cout << "생성자 실행 radius = " << radius << endl;
    }
    Circle(int r)
    {
        radius = r;
        cout << "생성자 실행 radius = " << radius << endl;
    }    
    ~Circle()
    {
        cout << "소멸자 실행 radius = " << radius << endl;
    }
    double getArea()
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    int radius;
    while(true)
    {
        cout << "정수 반지름 입력(음수가 입력되면 종료): ";
        cin >> radius;
        if(radius < 0) break;
        Circle* p = new Circle(radius);
        cout << "원의 면적은 " << p->getArea() << endl;
        delete p;
    }
    
    return 0;
}
