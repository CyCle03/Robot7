#include <iostream>
#include <cstdlib>
#include <memory>
using namespace std;

class Person {};
class Professor : public Person
{
public:
    Professor()
    {
        std::cout << "Professor 생성자 호출!" << std::endl;
    }
};

int main()
{
    Professor* lee = new Professor();
    delete lee;
    //smartpointer 기법을 사용해서 heap 메모리에 leesunsin을 생성하세요.
    std::unique_ptr<Professor> leeSunSin = std::make_unique<Professor>();

    
    return 0;
}
