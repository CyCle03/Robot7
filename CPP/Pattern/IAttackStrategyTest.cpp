#include <iostream>
#include <cstdlib>
using namespace std;

class IAttackStrategy
{
public:
    virtual void attack() = 0;
    virtual ~IAttackStrategy() = default;
};

class FireAttack : public IAttackStrategy
{
public:
    void attack() override
    {
        cout << "화공을 시전합니다." << endl;
    }
};

class WaterAttack : public IAttackStrategy
{
public:
    void attack() override
    {
        cout << "수공을 시전합니다." << endl;
    }
};

class PhysicalAttack : public IAttackStrategy
{
public:
    void attack() override
    {
        cout << "물리공격을 시전합니다." << endl;
    }
};

class Character
{
private:
    string name;
    IAttackStrategy* strategy = nullptr;
public:
    Character(string name) : name(name) {}
    void setStrategy(IAttackStrategy& s)
    {
        strategy = &s;
    }

    void attack()
    {
        if(!strategy)
        {
            cout << "공격 방식을 설정하지 않았습니다." << endl;
            return;
        }
        return strategy->attack();
    }
};

int main()
{
    Character hero("Lee Sun Sin");

    FireAttack fire;
    WaterAttack water;
    PhysicalAttack physical;

    hero.setStrategy(fire);
    hero.attack();
    hero.setStrategy(water);
    hero.attack();
    hero.setStrategy(physical);
    hero.attack();

    return 0;
}
