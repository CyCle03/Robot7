#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 20, b = 3;
	double result;

	result = ((double)a / (double)b);
	printf("a = %d, b = %d\n", a, b);
	printf("a / b의 결과 : %.1lf\n", result);

	a = (int)result;
	printf("(int) %.1lf의 결과 : %d\n", result, a);

	return 0;
}