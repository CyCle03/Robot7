#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	//문제: 정수 한 개를 입력받아 홀수와 짝수를 판별하라.
	//1. 변수선언 및 입력
	int N;

	printf("N? :");
	scanf("%d", &N);

	//2. 로직
	//3. 출력

	if (N % 2 != 0)
	{
		printf("홀수입니다.");
	}
	else
	{
		printf("짝수입니다.");
	}

	return 0;
}
