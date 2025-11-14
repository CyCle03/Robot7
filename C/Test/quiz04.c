#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 0, b = 0;
	int temp = 0;

	scanf("%d %d", &a, &b);

	temp = a;
	a = b;
	b = temp;

	printf("%d %d\n", a, b);

	return 0;
}
