#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec = {1,1,2,2,2,3,3,3};

    vector<int>::iterator it;
    
    it = unique(vec.begin(), vec.end());

    vec.erase(it, vec.end());
    
    for(int x : vec)
    {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}
