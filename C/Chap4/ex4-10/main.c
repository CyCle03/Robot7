#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 10, b = 20;
	int result = 2;

	a += 20;//a = a + 20
	result *= b + 10;

	printf("a = %d, b = %d\n", a, b);
	printf("result = %d\n", result);

	return 0;
}