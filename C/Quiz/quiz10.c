#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int plus(int a, int b);
int minus(int a, int b);
int multiple(int a, int b);
double divide(int a, int b);

int main()
{
	//사칙연산 함수 구현하기.
	int x = 0, y = 0;

	printf("두 정수를 입력하세요: ");
	scanf("%d %d", &x, &y);

	printf("plus : %d \n", plus(x, y));
	printf("minus : %d \n", minus(x, y));
	printf("multiple : %d \n", multiple(x, y));
	printf("divide : %.2lf \n", divide(x, y));

	return 0;
}

int plus(int a, int b)
{
	return a + b;
}

int minus(int a, int b)
{
	return a - b;
}

int multiple(int a, int b)
{
	return a * b;
}

double divide(int a, int b)
{
	return (double)a / (double)b;
}
