#include <iostream>
using namespace std;

class PrivateAccessError
{
private:
    int a;
    PrivateAccessError();
    void f();
public:
    int b;
    PrivateAccessError(int x);
    void g();
};

PrivateAccessError::PrivateAccessError()
{
    a = 1;
    b = 1;
}

PrivateAccessError::PrivateAccessError(int x)
{
    a = x;
    b = x;
}

void PrivateAccessError::f()
{
    a = 5;
    b = 5;
}

void PrivateAccessError::g()
{
    a = 6;
    b = 6;
}

int main()
{
    //PrivateAccessError objA; //default 생성자가 private기 때문에 접근 불가
    PrivateAccessError objB(100);
    //objB.a = 10; // a가 private이기 때문에 접근 불가
    objB.b = 20;
    //objB.f(); // 마찬가지로 f()가 private기 때문에 접근 불가
    objB.g();

    return 0;
}
