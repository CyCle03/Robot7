#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a , b;

	a = 10;
	b = 10;

	++a;
	--b;

	printf("a : %d\n", a);
	printf("b : %d\n", b);

	return 0;
}