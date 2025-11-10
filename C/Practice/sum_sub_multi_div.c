#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int plus(int a, int b);
int minus(int a, int b);
int multiple(int a, int b);
double divide(int a, int b);

int main()
{
	int num1 = 0, num2 = 0;

	printf("사칙연산을 할 두 정수를 입력하세요. : ");
	scanf("%d %d", &num1, &num2);

	printf("%d + %d = %d\n", num1, num2, plus(num1, num2));
	printf("%d - %d = %d\n", num1, num2, minus(num1, num2));
	printf("%d * %d = %d\n", num1, num2, multiple(num1, num2));
	printf("%d / %d = %.2lf\n", num1, num2, divide(num1, num2));


	return 0;
}

int plus(int a, int b)
{
	return (a + b);
}

int minus(int a, int b)
{
	return (a - b);
}

int multiple(int a, int b)
{
	return (a * b);
}

double divide(int a, int b)
{
	return ((double)a / (double)b);
}
