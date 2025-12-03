#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
using namespace std;

class Hero
{
protected:
    string name;
    string weapon;
public:
    Hero(string name = "영웅", string weapon = "막대기")
    {
        this->name = name;
        this->weapon = weapon;
    }

    virtual void attack()
    {
        cout << name << "이(가) " << weapon << "(으)로 공격" << endl;
    }
};

class Knight : public Hero
{
public:
    Knight() : Hero("기사", "검")
    {
    }
    void attack() override
    {
        cout << name << "이(가) " << weapon << "(으)로 공격" << endl;
    }
};

class Archer : public Hero
{
public:
    Archer() : Hero("궁수", "활")
    {
    }
    void attack() override
    {
        cout << name << "이(가) " << weapon << "(으)로 공격" << endl;
    }
};

class Wizard : public Hero
{
public:
    Wizard() : Hero("마법사", "지팡이")
    {
    }
    void attack() override
    {
        cout << name << "이(가) " << weapon << "(으)로 공격" << endl;
    }
};

int main()
{
    vector<Hero*> heroes;

    unique_ptr<Hero> knight = make_unique<Knight>();
    unique_ptr<Hero> archer = make_unique<Archer>();
    unique_ptr<Hero> wizard = make_unique<Wizard>();

    heroes.push_back(knight.get());
    heroes.push_back(archer.get());
    heroes.push_back(wizard.get());

    // knight->attack();
    // archer->attack();
    // wizard->attack();
    
    for(const auto& hero : heroes)
    {
        hero->attack();
    }

    return 0;
}
