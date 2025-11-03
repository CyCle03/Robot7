#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	//1단계
	int N = 0;

	printf("N? :");
	scanf("%d",&N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");

	//2단계
	for (int i = 0; i < N; i++)
	{
		for (int j = N; j > i; j--)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");

	//3단계
	for (int i = 0; i < N; i++)
	{
		for (int j = N-1; j > i; j--)
		{
			printf(" ");
		}
		for (int k = 0; k <= i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");

	//4단계
	for (int i = 0; i < N; i++)
	{
		for (int j = 0 ; j < i; j++)
		{
			printf(" ");
		}
		for (int k = N; k > i; k--)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");

	//5단계
	for (int i = 0; i <= (N / 2); i++)
	{
		for (int j = (N / 2); j > i; j--)
		{
			printf(" ");
		}
		printf("*");
		for (int k = 0; k < i; k++)
		{
			printf("*");
		}
		for (int l = 0; l < i; l++)
		{
			printf("*");
		}
		for (int n = (N / 2); n > i; n--)
		{
			printf(" ");
		}
		printf("\n");
	}
	for (int m = 1; m <= (N / 2); m++)
	{
		for (int o = 0; o < m; o++)
		{
			printf(" ");
		}
		printf("*");
		for (int p = (N / 2); p > m; p--)
		{
			printf("*");
		}
		for (int q = (N / 2); q > m; q--)
		{
			printf("*");
		}
		for (int r = 0; r < m; r++)
		{
			printf(" ");
		}
		printf("\n");
	}

	return 0;
}
