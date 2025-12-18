//#include "opencv2/opencv.hpp"
extern void show1();//이 파일 바깥에 있어.
extern void show2();
#include <iostream>

int main()
{
    std::cout << "OpneCV!\n";
    show1();
    show2();
}
