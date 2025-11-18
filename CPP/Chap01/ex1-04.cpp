#include <iostream>

int main()
{
    //1. 변수 선언 및 입력
    int score = 0, div = 0;
    
    std::cout << "점수를 입력하세요 : ";
    std::cin >> score;

    //1.5 입력 예외처리
    if (score > 100 || score < 0)
    {
        std::cout << "잘못된 점수입니다." << std::endl;

        return 0;
    }

    //2. 로직
    div = score / 10;
    switch (div)
    {
    case 10:
    case 9:
        std::cout << "A 입니다." << std::endl;
        break;
    case 8:
        std::cout << "B 입니다." << std::endl;
        break;
    case 7:
        std::cout << "C 입니다." << std::endl;
        break;
    case 6:
        std::cout << "D 입니다." << std::endl;
        break;
    default:
        std::cout << "F 입니다." << std::endl;
        break;
    }

    return 0;
}
