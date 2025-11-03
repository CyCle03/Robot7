#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 10;
	double b = 3.4;

	printf("int형 변수의 크기 : %d\n", sizeof(a));
	printf("double형 변수의 크기 : %d\n", sizeof(b));
	printf("정수형 상수의 크기 : %d\n", sizeof(10));
	printf("실수형 상수의 크기 : %d\n", sizeof(3.141592653));
	printf("수식의 결괏값의 크기 : %d\n", sizeof(1.5 + 3.4));
	printf("short 자료형의 크기 : %d\n", sizeof(short));
	printf("char 자료형의 크기 : %d\n", sizeof(char));

	return 0;
}