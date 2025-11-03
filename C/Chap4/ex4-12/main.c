#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 10, b = 20, result;

	result = (a > b) ? a : b;
	printf("큰 값 : %d\n", result);

	result = (a < b) ? a : b;
	printf("작은 값 : %d\n", result);

	if (a > b)
	{
		result = a;
	}
	else
	{
		result = b;
	}
	printf("큰 값 : %d\n", result);

	return 0;
}