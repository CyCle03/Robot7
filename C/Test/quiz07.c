#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	for (int i = 2; i <= 100; i++)
	{
		for (int j = 2; j <= i; j++)
		{
			if (i == j)
			{
				printf("%d ", i);
			}
			else if (i % j == 0)
			{
				break;
			}
		}
	}

	return 0;
}
