#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int total = 1, num = 0;

	scanf("%d", &num);

	if (num == 1)
	{
		printf("no\n");
	}
	else if (num > 1 && num <= 1000)
	{
		for (int i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				total += i;
			}
		}
		if (num == total)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	else
	{
		printf("0 < n <= 1000\n");
	}
	

	return 0;
}
