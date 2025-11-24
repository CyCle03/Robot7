#include <iostream>
#include <cstdlib>
#include <memory>
#include <string>
using namespace std;

class TV
{
protected:
    int size;
public:
    TV() 
    {
        size = 20;
    }
    TV(int size)
    {
        this->size = size;
    }
    int getSize()
    {
        return size;
    }
};

class WideTV : public TV
{
protected:
    bool videoIn;
public:
    WideTV(int size, bool videoIn) : TV(size)
    {
        this->videoIn = videoIn;
    }
    bool getVideoIn()
    {
        return videoIn;
    }
};

class SmartTV : public WideTV
{
protected:
    string ipAddr;
public:
    SmartTV(string ipAddr, int size) : WideTV(size, true)
    {
        this -> ipAddr = ipAddr;
    }
    string getIpAddr()
    {
        return ipAddr;
    }
};

int main()
{
    SmartTV htv("192.0.0.1", 32);
    cout << "size= " << htv.getSize() << endl;
    cout << "videoIn= " << boolalpha << htv.getVideoIn() << endl;
    cout << "IP= " << htv.getIpAddr() << endl;
    
    return 0;
}
