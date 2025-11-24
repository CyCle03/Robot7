#include <iostream>
using namespace std;

template <class T>
void mySwap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 4, b = 5;// int가 아닌 double, char 어느 변수라도 가능
    mySwap(a, b);

    cout << "a: " << a << " b: " << b << endl;
    return 0;
}
