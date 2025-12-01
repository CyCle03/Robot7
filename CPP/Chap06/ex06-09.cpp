#include <iostream>
using namespace std;

// void msg(int id)
// {
//     cout << id << endl;
// }

void msg(int id, string s= " ")
{
    cout << "ID: " << id << ", Message: " << s << endl;
}

int main()
{
    msg(6);
    msg(5, "Good Moring");

    return 0;
}
