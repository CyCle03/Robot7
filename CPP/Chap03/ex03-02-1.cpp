#include <iostream>

class Rectangel
{
public:
    int width;
    int height;

    int getArea()
    {
        return width * height;
    }
};

int main()
{
    Rectangel rect;
    rect.width = 3;
    rect.height = 5;
    std::cout << "사각형의 면적은 " << rect.getArea() << std::endl;

    return 0;
}
