#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int factorial(int n);

int result = 1;

int main()
{
	int num = 0;

	scanf("%d", &num);
	factorial(num);

	printf("%d", result);

	return 0;
}

int factorial(int n)
{
	if (n > 1)
	{
		result *= n;
		factorial(n - 1);
	}
	else
	{
		return 0;
	}
	return 0;
}
