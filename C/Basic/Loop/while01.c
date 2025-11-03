#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	// 1~100까지 합 -> while문으로 작성

	int i = 0;//초기값
	int sum = 0;

	while (i < 100)
	{
		sum += ++i;
	}

	printf("sum : %d i: %d\n", sum, i);

	return 0;
}
