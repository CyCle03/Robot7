#include <iostream>
#include <ios>
#include <iomanip>//c++ 소수점 구하기
#include <string>

int main()
{
    using namespace std;

    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "Pleas enter your midterm and final exam grades : ";
    double midterm, final;
    cin >> midterm >> final;

    cout << " Eter all your homework grades, " "followed by end-of-file: ";

    int count = 0;
    double sum = 0;

    double x;

    while (cin >> x)
    {
        ++count;
        sum += x;
    }

    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3) << 0.2 * midterm + 0.4 * final + 0.4 * sum / count << setprecision(prec) << endl;

    return 0;
}
