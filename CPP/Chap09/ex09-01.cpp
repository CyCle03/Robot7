#include <iostream>
#include <memory>

using namespace std;

class Parent
{
public:
    /*virtual*/ void f() { cout << "Parent::f() called" << endl; }
};

class Child : public Parent
{
public:
    void f() /*override*/ { cout << "Child::f() called" << endl; }
};

int main()
{

    unique_ptr<Child> child = make_unique<Child>();
    child->f();  // Calls Child::f()

    unique_ptr<Parent> parent = make_unique<Child>();
    parent->f();  // Calls Parent::f() due to static binding

    // Child d; 
    // Child* pDer;
    // pDer = &d;
    // pDer->f();  // Calls Child::f()

    //unique_ptr<Child> pDer = make_unique<Child>();
    return 0;
}
