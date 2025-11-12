#include<stdio.h>

int divisor(int num);

int main()
{
    int num;
    printf("1000 이하의 자연수를 입력하세요 : ");
    scanf("%d", &num);

    printf("%d의 약수는 : ",num);
    
    if(num == divisor(num) && num != 1)
    {
        printf("\n%d : 완전수\n", num);
    }
    else
    {
        printf("\n%d : 완전수가 아닙니다.\n", num);
    }

    return 0;
}

int divisor(int num)
{
    static int div = 2;
    static int total = 1;

    if(num > 2)
    {    
        if(div < num)
        {
            if(num % div == 0)
            {
                printf("%d ", div);
                total += div;
            }
            div++;
            divisor(num);
        }
    }
    return total;
}
