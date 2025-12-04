#include <iostream>
#include <memory>
using namespace std;

class MagicStrategy
{
public:
    virtual void cast(const string& target) = 0;
    virtual ~MagicStrategy() = default;
};

class FireMagic : public MagicStrategy
{
    public:
    void cast(const string& target) override
    {
        cout << "화염 마법을 " << target <<"에게 시전합니다!" << endl;
    }
};

class IceMagic : public MagicStrategy
{
    public:
    void cast(const string& target) override
    {
        cout << "얼음 마법을 " << target <<"에게 시전합니다!" << endl;
    }
};

class MagicUser
{
private:
    string name;
    unique_ptr<MagicStrategy> strategy;
public:
    MagicUser(string name) : name(name) {}
    void setStrategy(unique_ptr<MagicStrategy> s)
    {
        strategy = move(s);
    }
    void cast(const string& target)
    {
        if(!strategy)
        {
            cout << "마법 방식을 설정하지 않았습니다." << endl;
            return;
        }
        cout << name << "이(가) ";
        strategy->cast(target);
    }
};

int main()
{
    MagicUser mage("해리");

    FireMagic fireMagic;

    while(true)
    {
        cout << "--------------------------------------------" << endl;
        cout << "=== 해리 포터 마법 전투 시뮬레이터 ===" << endl;
        cout << "1. 화염 마법 설정" << endl;
        cout << "2. 얼음 마법 설정" << endl;
        cout << "3. 마법 시전" << endl;
        cout << "0. 종료" << endl;
        cout << "선택: ";
        int choice;
        cin >> choice;

        if(choice == 1)
        {
            mage.setStrategy(make_unique<FireMagic>());
            cout << "화염 마법이 설정되었습니다." << endl;
        }
        else if(choice == 2)
        {
            mage.setStrategy(make_unique<IceMagic>());
            cout << "얼음 마법이 설정되었습니다." << endl;
        }
        else if(choice == 3)
        {
            string target;
            cout << "마법을 시전할 대상을 입력하세요: ";
            cin >> target;
            mage.cast(target);
        }
        else if(choice == 0)
        {
            cout << "마법 전투 시뮬레이터를 종료합니다." << endl;
            break;
        }
        else
        {
            cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
        }
        cout << "--------------------------------------------" << endl;
    }

    return 0;
}
