#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char* name;
    int id;
public:
    Person(int id, const char* name)
    {
        this->id = id;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    ~Person()
    {
        delete[] name;
    }
    void changeName(const char* newName)
    {
        if(strlen(newName) > strlen(name))
        {
            return;
        }
        strcpy(name, newName);
    }
    void show()
    {
        cout << "id: " << id << ',' << name << endl;
    }
};

int main()
{
    Person father(1, "Kitae");
    Person daughter(father);
    
    cout << "daughter 객체 생성 직후 ----" << endl;
    father.show();
    daughter.show();

    daughter.changeName("Grace");
    cout << "daughter 이름을 Grace로 변경한 후 ----" << endl;
    father.show();
    daughter.show();

    return 0;
}
