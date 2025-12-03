#include <iostream>
#include <memory>
using namespace std;

class Shape
{
public:
    virtual void draw() 
    {
        cout << "Shape을 그린다." << endl;
    }
};
class Circle : public Shape
{
public:
    void draw() override { cout << "Circle을 그린다." << endl; }
};
class Rect : public Shape
{
public:
    void draw() override { cout << "Rect를 그린다." << endl; }
};
class Line : public Shape
{
public:
    void draw() override { cout << "Line을 그린다." << endl; }
};

void paint(Shape* p)
{
    p->draw();
    
    delete p;
}

int main()
{
    paint(new Circle());
    paint(new Rect());
    paint(new Line());

    return 0;
}
