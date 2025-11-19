#include <iostream>

class Car
{
public:
    int speed;
    std::string brand;
    std::string color;

    Car():speed(0), brand("현대"), color("하얀색")
    {
        std::cout << "Car 객체가 생성되었습니다." << std::endl;
    }

    Car(int speed, std::string brand, std::string color)
    : speed(160), brand("Kia"), color("검은색")
    {}

    ~Car()
    {
        std::cout << "Car 객체가 소멸되었습니다." << std::endl;
    }
};

int main()
{
    Car myCar; // 객체를 Stack 메모리에 만들었다.
    std::cout << "speed : " << myCar.speed << std::endl;
    std::cout << "brand : " << myCar.brand << std::endl;
    std::cout << "color : " << myCar.color << std::endl << std::endl;

    Car* myCar2 = new Car();
    std::cout << "speed : " << myCar2->speed << std::endl;
    std::cout << "brand : " << myCar2->brand << std::endl;
    std::cout << "color : " << myCar2->color << std::endl << std::endl;

    Car* myCar3 = new Car(160, "Kia", "검은색");
    std::cout << "speed : " << myCar3->speed << std::endl;
    std::cout << "brand : " << myCar3->brand << std::endl;
    std::cout << "color : " << myCar3->color << std::endl << std::endl;

    delete myCar2;
    delete myCar3;

    return 0;
}
