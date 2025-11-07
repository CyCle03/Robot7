#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int number;

	printf("홀,짝을 판별할 정수를 입력하세요: ");
	scanf("%d", &number);

	if (number % 2 != 0)
	{
		printf("홀수\n");
	}
	else
	{
		printf("짝수\n");
	}


	return 0;
}
