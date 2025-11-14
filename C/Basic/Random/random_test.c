#include<stdio.h>
#include<stdlib.h>
#include<time.h>//1970.01.01 00시 기준

int main()
{
    srand((unsigned int)time(NULL));//random의 초기값을 잡는다.
    //시드값을 고정하면 동일한 변수가 나온다.

    for(int i = 0; i < 6; i++)
    {
        int number = rand() % 45 + 1;//1 ~ 45;
        printf("난수 : %d\n", number);
    }

    return 0;
}
