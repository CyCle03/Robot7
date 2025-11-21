#include <iostream>
#include <cstdlib>
#include <memory>

class Circle
{
public:
    int radius;
    Circle(int r)
    {
        radius = r;
    }
    void draw()
    {
        std::cout << "원을 그리다." << std::endl;
    }
};

int main()
{
    //동적할당
    int* p = new int;
    *p = 5;
    delete p;

    //배열의 동적할당
    int* p2 = new int[3];
    p2[0] = 0;
    p2[1] = 1;
    delete [] p;

    //c++11 smartpointer
    std::unique_ptr<int> p3 = std::make_unique<int>(5);
    std::unique_ptr<Circle> p4 = std::make_unique<Circle>(10);
    p4->draw();
    
    return 0;
}
