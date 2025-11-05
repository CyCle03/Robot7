#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int factorial(int n);

int main()
{
	int num = 0;

	scanf("%d", &num);

	printf("%d", factorial(num));

	return 0;
}

int factorial(int n)
{
	if (n > 0)
	{
		return n * factorial(n - 1);
	}
	else
	{
		return 1;
	}
}
