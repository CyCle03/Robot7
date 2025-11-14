#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int N = 0;

	printf("N? ");
	scanf("%d", &N);

	printf("\n");

	for (int i = 0; i <= N / 2 ; i++)
	{
		for (int j = N / 2; j > i ; j--)
		{
			printf(" ");
		}
		printf("*");
		for (int k = 0; k < i ; k++)
		{
			printf("**");
		}
		printf("\n");
	}
	for (int i = 1; i <= N / 2; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf(" ");
		}
		printf("*");
		for (int k = N / 2; k > i; k--)
		{
			printf("**");
		}
		printf("\n");
	}

	return 0;
}
