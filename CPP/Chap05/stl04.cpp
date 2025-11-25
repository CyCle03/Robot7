#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, string> dic;

    dic.insert(make_pair("love", "사랑"));
    //dic["love"] = "사랑";

    string kor = dic["love"];
    //string kor = dic.at("love");

    cout << kor <<endl;

}
