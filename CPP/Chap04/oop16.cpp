#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
using namespace std;

class Hero
{
public:
    virtual void attack()
    {
        cout << "기본 공격" << endl;
    }
};

class Knight : public Hero
{
public:
    void attack() override
    {
        cout << "기사 공격" << endl;
    }
};

class Wizard : public Hero
{
public:
    void attack() override
    {
        cout << "마법사 공격" << endl;
    }

};

int main()
{
    vector<Hero*> list;

    list.push_back(new Hero());
    list.push_back(new Knight());
    list.push_back(new Wizard());

    for(Hero* p : list)
    {
        p->attack();
        delete p;
    }

    
    return 0;
}
