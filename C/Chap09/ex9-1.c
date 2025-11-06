#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a;
	double b;
	char c;

	printf("int형 변수의 주소 : %u\n", &a);
	printf("int형 변수의 주소 : %p\n\n", &a);

	printf("double형 변수의 주소 : %u\n", &b);
	printf("double형 변수의 주소 : %p\n\n", &b);

	printf("char형 변수의 주소 : %u\n", &c);
	printf("char형 변수의 주소 : %p\n", &c);

	return 0;
}
