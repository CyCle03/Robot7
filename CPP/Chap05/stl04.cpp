#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, string> dic;

    dic.insert(make_pair("love", "사랑"));
    dic["world"] = "세계";

    string kor1 = dic["love"];
    string kor2 = dic.at("world");

    cout << kor1 <<endl;
    cout << kor2 <<endl;

}
