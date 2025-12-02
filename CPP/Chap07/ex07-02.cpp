#include <iostream>
using namespace std;

class Rect;//전방 선언

class RectManager//RectManager 클래스 선언
{
public:
    bool equals(Rect r, Rect s);//멤버 함수 선언
};

class Rect
{
private:
    int width;
    int height;
public:
    Rect(int width, int height) {this->width = width; this->height = height;}
    friend bool RectManager::equals(Rect r, Rect s);//friend 선언
};

bool RectManager::equals(Rect r, Rect s)//멤버 함수 정의
{
    if(r.width == s.width && r.height == s.height)
        return true;
    else
        return false;
}

int main()
{
    Rect a(3,4) , b(4,5);
    RectManager manager;
    if(manager.equals(a,b))
        cout << "같다" << endl;
    else
        cout << "같지 않다" << endl;
 
    return 0;
}
