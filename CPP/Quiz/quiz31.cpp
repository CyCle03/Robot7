#include <iostream>

class Point
{
    int x, y;
public:
    Point():Point(0,0) {}
    Point(int a, int b):x(a), y(b)
    {
        std::cout << "( " << x << " , " << y << " )" <<std::endl;
    }
};

int main()
{
    Point point1;
    Point point2(5, 5);
    
    return 0;
}
