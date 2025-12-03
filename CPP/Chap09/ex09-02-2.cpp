#include <iostream>
#include <memory>
using namespace std;

class Shape
{
public:
    virtual void draw() = 0;
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

void paint(Shape& p)
{
    p.draw();
}

int main()
{
    Circle c;
    Rect r;
    Line l;
    paint(c);
    paint(r);
    paint(l);

    return 0;
}
