#include <iostream>
#include <cstdlib>
using namespace std;

class Circle
{
public:
    int radius;
    //Circle() {}
    Circle(int r)
    {
        radius = r;
    }
    double getArea()
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    //Circle waffle(15);
    Circle circleArray[3] = {Circle(10),Circle(20),Circle(30)};
    cout << "프로그램이 동작하였습니다!" << endl;

    return 0;
}
