#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int arr1[3][3] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t", arr1[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	int arr2[5][5] = { 0 };

	for (int m = 0; m < 5; m++)
	{
		for (int n = 0; n < 5; n++)
		{
			printf("%d\t", arr2[m][n]);
		}
		printf("\n");
	}

	return 0;
}
