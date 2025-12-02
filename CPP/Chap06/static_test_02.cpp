#include <iostream>
using namespace std;

class Human
{
public:
    void run()
    {
        cout << "달리다." << endl;
    }
    static void jump()
    {
        cout << "뛰다." << endl;
    }
};

// void run()
// {
//     cout << "달리다." << endl;
// }

int main()
{
    //run();
    Human human;
    human.run();

    Human::jump();

    return 0;
}
