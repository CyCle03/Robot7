#include <iostream>

int main()
{
    int score;
    char grade;

    std::cout << "점수를 입력하세요. : ";
    std::cin >> score;

    if (score > 100 || score < 0)
    {
        std::cout << "잘못된 점수입니다." << std::endl;

        return 1;
    }
    else if (score <= 100 && score >= 90)
    {
        grade = 'A';
    }
    else if (score >= 80)
    {
        grade = 'B';
    }
    else if (score >= 70)
    {
        grade = 'C';
    }
    else if (score >= 60)
    {
        grade = 'D';
    }
    else if(score >= 0)
    {
        grade = 'F';
    }

    std::cout << score << "점은 " << grade << "등급 입니다." << std::endl;

    return 0;
}
