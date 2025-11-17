#include <iostream>
#include <string>

int main()
{
    std::cout << "당신의 첫 번째 이름을 입력하세요 : ";
    std::string name; //string 변수 선언
    std::cin >> name;

    //인사말 작성
    std::cout << "Hello, " << name << "!" << std::endl;
}
