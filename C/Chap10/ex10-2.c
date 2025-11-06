#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int ary[3];
	int* pa; 
	pa = ary;
	
	*pa = 10;
	*(pa + 1) = 20;
	pa[2] = pa[0] + pa[1];

	for (int i = 0; i < 3; i++)
	{
		printf("%-5d", pa[i]);
	}

	return 0;
}
