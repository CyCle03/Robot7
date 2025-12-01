#include <iostream>
#include <cstdlib>
#include <memory>
using namespace std;

class Calculator
{
private:
    int num1, num2;
public:
    Calculator()
    {
        num1 = 1;
        num2 = 1;
    }
    Calculator(int num1, int num2)
    {
        this->num1 = num1;
        this->num2 = num2;
    }
    void setNum()
    {
        cout << "사칙연산을 할 두 정수를 입력하세요.: ";
        cin >> num1 >> num2;
        cout << endl;
    }
    int sum()
    {
        return num1 + num2;
    }
    int sub()
    {
        return num1 - num2;
    }
    int multiple()
    {
        return num1 * num2;
    }
    double divide()
    {
        return (double)num1 / num2;
    }
};

int main()
{
    unique_ptr<Calculator> calculator = make_unique<Calculator>();

    calculator->setNum();
    cout << "plus : " << calculator->sum() << endl
    << "minus : " << calculator->sub() << endl
    << "multiple : " << calculator->multiple() << endl
    << "divide : " << calculator->divide() << endl;
    
    return 0;
}
