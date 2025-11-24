#include <iostream>
#include <cstdlib>
#include <memory>
using namespace std;

class Person
{};

class Student : public Person
{};

int main()
{
    Person father; // stack- delext(x)
    unique_ptr<Person> gilDong = make_unique<Person>();//heap객체생성 delete(x)

    Person* gilDong2 = new Student();
    delete gilDong2;

    return 0;
}
