#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    int total = 0;
    cout << "국어, 영어, 수학 성적을 입력하세요. : ";
    for(int i = 0; i < 3; i++)
    {
        int score;
        cin >> score;
        v.push_back(score);
        total += v[i];
    }

    double avg = (double)total / v.size(); 

    cout << "총점 : " << total << ", 평균 : " << avg << endl;
    
    return 0;
}
