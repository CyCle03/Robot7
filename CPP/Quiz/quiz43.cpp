#include <iostream>
#include <string>
using namespace std;

class Triangle
{
private:
    int width, height;
public:
    Triangle()
    {
        this->width = 1;
        this->height = 1;
    }
    Triangle(int width, int height)
    {
        this->width = width;
        this->height = height;
    }

    double getArea()
    {
        return width * height * 0.5;
    }
};

int main()
{
    string width, height;

    cout << "넓이를 구할 삼각형의 밑변과 높이를 입력하세요. :";
    getline(cin, width, ' ');
    getline(cin, height);

    Triangle tri(stoi(width), stoi(height));

    cout << "삼각형의 넓이는 : " << tri.getArea() << endl;
    return 0;
}
