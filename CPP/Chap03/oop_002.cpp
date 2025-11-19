#include <iostream>

class Dog
{
public:
    bool male;
    int age;
    int weight;

public:
    Dog()
    {
        //디폴트 생성자   
    }
    ~Dog()
    {
        //리소스 반환, 객체가 가지고 있는 자원이 있다면 이때 해제한다.
    }

public:
    void Bark()
    {
        std::cout << "멍멍" << std::endl;
    }
    void Eat()
    {
        std::cout << "먹습니다." << std::endl;
    }
    void Sleep()
    {
        std::cout << "잠을 잡니다." << std::endl;
    }
};

int main()
{
    Dog zzong;
    zzong.age = 5;
    zzong.male = true;
    zzong.weight = 7;

    std::cout << "쫑의 나이는 : " << zzong.age << "kg 입니다." << std::endl;
    std::cout << "쫑의 몸무게는 : " << zzong.weight << "세 입니다." << std::endl;

    zzong.Bark();
    zzong.Eat();
    zzong.Sleep();

    return 0;
}
