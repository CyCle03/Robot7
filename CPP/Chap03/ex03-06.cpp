#include <iostream>

class Rectangle
{
public:
    int width;
    int height;

    Rectangle(): width(1), height(1)
    {}

    Rectangle(int length) : width(length), height(length)
    {}

    Rectangle(int _width, int _height) : width(_width), height(_height)
    {}

    bool isSquare()
    {
        if(width == height)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};

int main()
{
    Rectangle rect1;
    Rectangle rect2(3, 5);
    Rectangle rect3(3);

    if(rect1.isSquare()) std::cout << "rect1은 정사각형이다." << std::endl;
    if(rect2.isSquare()) std::cout << "rect2은 정사각형이다." << std::endl;
    if(rect3.isSquare()) std::cout << "rect3은 정사각형이다." << std::endl;

    return 0;
}
