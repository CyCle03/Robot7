#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 10, b = 5;
	int result;

	result = a / b * 2;
	printf("result = %d\n", result);
	result = ++a * 3;
	printf("result = %d\n", result);
	result = a > b && a != 5;
	printf("result = %d\n", result);
	result = a % 3 == 0;
	printf("result = %d\n", result);

	return 0;
}
