#include <iostream>

class Calculator
{
private:

public:
    int add(int x, int y)
    {
        return x + y;
    }
    
    int sub(int x, int y)
    {
        return x - y;
    }

    int multiple(int x, int y)
    {
        return x * y;
    }

    double divide(int x, int y)
    {
        return (double)x / y;
    }

};

int main()
{
    Calculator calculator;
    int a, b;

    std::cout << "사칙연산을 할 두 정수를 입력하세요. >>";
    std::cin >> a >> b;

    std::cout << a << " + " << b << " = " << calculator.add(a , b) << std::endl; 
    std::cout << a << " - " << b << " = " << calculator.sub(a , b) << std::endl;
    std::cout << a << " * " << b << " = " << calculator.multiple(a , b) << std::endl;
    std::cout << a << " / " << b << " = " << calculator.divide(a , b) << std::endl;

    return 0;
}
