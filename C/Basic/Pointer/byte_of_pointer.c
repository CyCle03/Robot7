#include <stdio.h>

int main()
{
    int ary[3];
    int* pa = ary;
    
    printf("%d %d\n", sizeof(ary), sizeof(pa));

    return 0;
}
