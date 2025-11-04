#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int sum(int x, int y);//함수 선언, 함수 헤더.

int main()
{
	int a = 10, b = 20;
	int result;

	result = sum(a,b);
	printf("result : %d\n", result);

	return 0;
}

int sum(int x, int y)//두 정수를 더해서 돌려주자.
{
	int temp;

	temp = x + y;

	return temp;
}
