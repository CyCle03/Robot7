#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> odd_vector;

    for(int i = 1; i < 21; i++)
    {
        odd_vector.push_back(i);
    }

    for_each(odd_vector.begin(), odd_vector.end(), [](int n){ if(n%2 != 0) cout << n << " " ; });

    
    return 0;
}
