#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector <string> sv;
    string name;

    cout << "이름을 5개 입력하라" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : ";
        getline(cin, name);
        sv.push_back(name);
    }

    
    sort(sv.begin(), sv.end());

    for(int i = 0; i < sv.size(); i++)
    {
        cout << sv[i] << " ";
    }
    cout << endl;
}
