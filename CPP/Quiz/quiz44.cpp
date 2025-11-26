#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    list<string> strList;
    string str;

    auto it = strList.begin();
    for(int i = 0; i < 5; i++)
    {
        cout << "이름 >> ";
        getline(cin, str);
        strList.insert(it++, str);
    }
    cout << endl;

    strList.sort();

    cout << "사전에서 가장 뒤에 나오는 문자열은 " << *it << endl;//list.back()

    return 0;
}
