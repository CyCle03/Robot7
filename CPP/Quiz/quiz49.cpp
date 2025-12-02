#include <iostream>

using namespace std;

class Car
{
private:
    string brand;
    int speed;
    string color;

    Car(string brand, int speed, string color)
    {
        this->brand = brand;
        this->speed = speed;
        this->color = color;
    }

public:
    class Builder
    {
    private:
        string brand = "Kia";
        int speed = 100;
        string color = "White";
    public:
        Builder& setBrand(const string& brand)
        {
            this->brand = brand;
            return *this;
        }
        Builder& setSpeed(int speed)
        {
            this->speed = speed;
            return *this;
        }
        Builder& setColor(const string& color)
        {
            this->color = color;
            return *this;
        }
        Car build()
        {
            return Car(brand, speed, color);
        }
    };
    void displayInfo() const
    {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h, Color: " << color << endl;
    }
};

int main()
{
    Car myCar = Car::Builder()
                    .setBrand("Hyundai")
                    .setSpeed(150)
                    .setColor("Red")
                    .build();
    myCar.displayInfo();
    
    return 0;
}
