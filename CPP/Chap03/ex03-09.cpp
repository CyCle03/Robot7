#include <iostream>
using namespace std;

class PrivateAccessError
{
private:
    int a;
    PrivateAccessError();
public:
    int b;
    PrivateAccessError(int x);
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

int main()
{
    //PrivateAccessError objA; //default 생성자가 private기 때문에 에러
    PrivateAccessError objB(100);

    return 0;
}
