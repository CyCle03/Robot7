#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    std::cout << "입력할 정수의 개수: ";
    cin >> n;
    
    int* p = new int[n];

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        std::cout << i + 1 << ": ";
        cin >> p[i];
        sum += p[i];
    }

    cout << "총합은 " << sum;

    delete []p;

    return 0;
}
