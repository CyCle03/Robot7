#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int ary[3];
	int* pa; 
	pa = ary;
	
	*pa = 10;//ary[0]
	*(pa + 1) = 20;//ary[1]
	pa[2] = pa[0] + pa[1];//ary[2] = ary[0] + ary[1]

	for (int i = 0; i < 3; i++)
	{
		printf("%-5d", pa[i]);
	}

	return 0;
}
