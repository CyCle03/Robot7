#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 10, b = 20, result;

	result = (a > b) ? a : b;
	printf("Å« °ª : %d\n", result);

	result = (a < b) ? a : b;
	printf("ÀÛÀº °ª : %d\n", result);

	if (a > b)
	{
		result = a;
	}
	else
	{
		result = b;
	}
	printf("Å« °ª : %d\n", result);

	return 0;
}
