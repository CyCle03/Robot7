#include <iostream>
using namespace std;

class Power
{
private:
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch = 0) { this->kick = kick; this->punch = punch; }
    void show()
    {
        cout << "kick: " << kick << ", punch: " << punch << endl;
    }
    Power operator- (Power other)
    {
        Power temp;
        temp.kick = this->kick + other.kick;
        temp.punch = this->punch + other.punch;
        return temp;
    }
};

int main()
{
    Power a(3,5), b(4,6), c;
    c = a - b; // b.operator-(a) 호출
    a.show();
    b.show();
    c.show();

    return 0;
}
