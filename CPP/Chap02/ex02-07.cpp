#include <iostream>
#include <string>

int main()
{
    using namespace std;

    string song;
    song = "Falling in love with you";
    string elvis("Elvis Presley");
    string singer;

    cout << song + "를 부른 가수는";
    cout << "(힌트 : 첫 글자는 " << elvis[0] << ")?";

    getline(cin, singer);// 문자열 입력 방법 중 가장 많이 사용
    if(singer == elvis)
    {
        cout << "맞았습니다." << endl;
    }
    else
    {
        cout << "틀렸습니다. " + elvis + "입니다." << endl;
    }

    return 0;
}
