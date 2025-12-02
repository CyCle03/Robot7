#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int age;
    string major;
    int id;

    Student(const string& name, int age, const string& major, int id)
        : name(name), age(age), major(major), id(id) {}
public:
    class Builder
    {
    private:
        string name;
        int age = 20;
        string major;
        int id;
    public:
        Builder& setName(const string& name)
        {
            this->name = name;
            return *this;
        }
        Builder& setAge(int age)
        {
            this->age = age;
            return *this;
        }
        Builder& setMajor(const string& major)
        {
            this->major = major;
            return *this;
        }
        Builder& setId(int id)
        {
            this->id = id;
            return *this;
        }
        Student build()
        {
            return Student(name, age, major, id);
        }
    };
        string getName()
        {
            return name;
        }
        int getAge()
        {
            return age;
        }
        string getMajor()
        {
            return major;
        }
        int getId()
        {
            return id;
        }
};

int main()
{
    Student student = Student::Builder()
                        .setName("홍길동")
                        .setAge(20)
                        .setMajor("Embedded Systems")
                        .setId(20251234)
                        .build();

    cout << "Student Information:" << endl;
    cout << "Name: " << student.getName() << endl;
    cout << "Age: " << student.getAge() << endl;
    cout << "Major: " << student.getMajor() << endl;
    cout << "ID: " << student.getId() << endl;

    return 0;
}
