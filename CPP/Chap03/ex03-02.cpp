#include <iostream>

struct studentInfo
{
    char bloodType;
    int stdNumber;
    double grade;
};

typedef struct studentinfo StudentInfo;

int main()
{
    using namespace std;

    studentInfo si[2] = { {'O', 20031128, 3.5}, { 'A', 19961219, 2.3 } };

    for (int i = 0; i < 2; i++)
    {
        cout << "혈액형 : " << si[i].bloodType << endl;
        cout << "학번 : " << si[i].stdNumber << endl;
        cout << "성적 : " << si[i].grade << endl << endl;
    }


    return 0;
}
