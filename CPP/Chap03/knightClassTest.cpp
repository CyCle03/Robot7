#include <iostream>
using namespace std;

class Knight
{
public:
    //1. 멤버 변수
    int level;
    string name;
    int hp;
    int mp;
    
    //2. 생성자
    Knight():level(1), name("기사"), hp(100), mp(10)
    {}
    Knight(string name)
    {
        this->level = 1;
        this->name = name;
        this->hp = 100;
        this->mp = 10;
    }
    Knight(string name, int level)
    {
        this->level = level;
        this->name = name;
        this->hp = 100;
        this->mp = 10;
    }
    Knight(string name, int level, int hp, int mp)
    {
        this->level = level;
        this->name = name;
        this->hp = hp;
        this->mp = mp;
    }

    //3. 멤버 함수
    string attack()
    {
        return "공격하다.";
    }

    string attack(string weapon)
    {
        return weapon + "로 공격하다.";
    }

    string attack(string weapon, string ora)
    {
        return ora + " 보호막을 감싼 후 " + weapon + "로 공격하다.";
    }

    string eat()
    {
        return "먹는다.";
    }
};

int main()
{
    //Knight james;
    //Knight james("제임스");
    Knight james("제임스", 20, 90, 10);

    cout << "레벨 : " << james.level <<endl;
    //james.name = "제임스"; // 생성 후 초기화
    cout << "이름 : " << james.name <<endl;
    cout << "체력 : " << james.hp <<endl;
    cout << "마력 : " << james.mp <<endl;

    cout << james.attack() << endl;
    cout << james.attack("뿅망치") << endl;
    cout << james.attack("뿅망치", "화염") << endl;

    return 0;
}
