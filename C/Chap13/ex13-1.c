#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void assign();

int main()
{
	int a = 0;

	assign();
	printf("main 함수 a : %d\n", a);

	return 0;
}

void assign() 
{
	int a = 10;

	printf("assign 함수 a : %d\n", a);
}
