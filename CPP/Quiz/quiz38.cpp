#include <iostream>
#include <cstdlib>
#include <memory>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    
    cout << "뒤집을 문자열을 입력하세요 : ";
    getline(cin, str);

    reverse(str.begin(), str.end());

    int size = 0;
    for(int i = 0; i < 100; i++)
    {
        if(str[i] == '\0')
        {
            size = --i;
            break;
        }
        cout << str[i];
    }

    cout << endl << "size : " << size << endl;


    for(int i = size; i >= 0; i--)
    {
        cout << str[i];
    }
    cout << endl;

    return 0;
}
