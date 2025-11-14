#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N = 0;
	int arr[100][100];
	int num1 = 0, num2 = 0;
	
	scanf("%d", &N);
	
	num2 = N / 2;

	for (int i = 1; i <= N * N; i++)
	{
		arr[num1][num2] = i;

		if (i % N == 0)
		{
			num1++;
		}
		else
		{
			if (num1 == 0)
			{
				num1 = N - 1;
			}
			else
			{
				num1--;
			}
			if (num2 == N - 1)
			{
				num2 = 0;
			}
			else
			{
				num2++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}



	return 0;
}
