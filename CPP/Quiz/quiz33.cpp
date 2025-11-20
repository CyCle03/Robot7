#include <iostream>

class Cat
{
private:
    std::string name;
    bool male;
    int age;    
public:
    Cat():name("고양이"), male(true), age(1){}
    Cat(std::string _name, bool _male, int _age)
    {
        name = _name;
        male = _male;
        age = _age;
    }

    void setName(std::string _name)
    {
        name = _name;
    }
    std::string getName()
    {
        return name;
    }

    void setMale(bool _male)
    {
        male = _male;
    }
    bool getMale()
    {
        return male;
    }

    void setAge(int _age)
    {
        age = _age;
    }
    int getAge()
    {
        return age;
    }

};

int main()
{
    Cat navi;
    std::cout << "이름 : " << navi.getName() << 
    ", 성별(0암/1수) : " << navi.getMale() << 
    ", 나이 : " << navi.getAge() << std::endl;

    Cat* hodu = new Cat();
    hodu->setName("호두");
    hodu->setMale(false);
    hodu->setAge(3);
    std::cout << "이름 : " << hodu->getName() << 
    ", 성별(0암/1수) : " << hodu->getMale() << 
    ", 나이 : " << hodu->getAge() << std::endl;

    delete hodu;

    return 0;
}
