#include <iostream>
using namespace std;

class MathUtils
{
public:
    static int abs(int a) { return (a < 0) ? -a : a; }
    static int max(int a, int b) { return (a > b) ? a : b; }
    static int min(int a, int b) { return (a < b) ? a : b; }
};

int main()
{
    cout << MathUtils::abs(-5) << endl;
    cout << MathUtils::max(10, 8) << endl;
    cout << MathUtils::min(-3, -8) << endl;

    return 0;
}
