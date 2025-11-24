#include <iostream>

class Cookie
{
public:
    virtual void eat()
    {
        std::cout << "쿠키를 먹었습니다." << std::endl;
    }
};

class ButterCookie : public Cookie
{
public:
    void eat() override
    {
        std::cout << "버터쿠키를 먹었습니다." << std::endl;
    }
};

class ChocoCookie : public Cookie
{
public:
    void eat() override
    {
        std::cout << "초코쿠키를 먹었습니다." << std::endl;
    }
};

class ChocochipCookie : public Cookie
{
public:
    void eat() override
    {
        std::cout << "초코칩쿠키를 먹었습니다." << std::endl;
    }
};

int main()
{
    Cookie* cookie[4];
    cookie[0] = new Cookie();
    cookie[1] = new ButterCookie();
    cookie[2] = new ChocoCookie();
    cookie[3] = new ChocochipCookie();

    for(Cookie* c : cookie)
    {
        c->eat();
    }

    for(int i = 0; i < 4; i++)
    {
        delete cookie[i];
    }
    return 0;
}
