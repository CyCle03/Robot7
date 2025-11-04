#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int recursive(int n);

int main()
{
	recursive(0);

	return 0;
}

int recursive(int n)
{
	printf("number : %d\n", n);

	if (n == 10) return 0;

	recursive(n + 1);
}
