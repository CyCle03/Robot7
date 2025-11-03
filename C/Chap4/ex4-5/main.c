#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 10, b = 20, c = 10;
	int result;

	result = (a > b);
	printf("a > b : %d\n", result);
	result = (a >= b);
	printf("a >= b : %d\n", result);
	result = (a < b);
	printf("a < b : %d\n", result);
	result = (a <= b);
	printf("a <= b : %d\n", result);
	result = (a <= c);
	printf("a <= c : %d\n", result);
	result = (a == b);
	printf("a == b : %d\n", result);
	result = (a != c);
	printf("a != c : %d\n", result);

	a = 30;
	result = (a > 10) && (a < 20);
	printf("(a > 10) && (a < 20) : %d\n", result);
	result = (a < 10) || (a > 20);
	printf("(a < 10) || (a > 20) : %d\n", result);
	result = !(a >= 30);
	printf("! (a >= 30) : %d\n", result);

	return 0;
}