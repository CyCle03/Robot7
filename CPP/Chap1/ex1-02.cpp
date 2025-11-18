#include <iostream>

int g = 20;

int add(int x, int y)
{
    return x + y;
}

int main()
{
    int a, b, sum;


    std::cout << "두 정수를 입력하세요. : ";
    std::cin >> a >> b;

    sum = add(a, b);

    std::cout << a << " + " << b << " = " << sum << std::endl;

    return 0;
}
