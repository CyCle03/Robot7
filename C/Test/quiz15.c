#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

enum state
{
	Right,
	Down,
	Left,
	Up
};

int main()
{
	int arr[5][5] = { 0 };
	int num1 = 0, num2 = 0;
	int lim_num1 = 5, lim_num2 = 5;
	enum state st = Right;

	for (int i = 1; i <= 5 * 5; i++)
	{
		arr[num1][num2] = i;
		switch (st)
		{
		case Right:
			if (arr[num1 + 1][num2] == 0)
			{
				num1++;
			}
			else
			{
				st = Down;
			}
		case Down:
			if (arr[num1][num2 + 1] == 0)
			{
				num2++;
			}
			else
			{
				st = Left;
			}
		case Left:
			if (arr[num1 - 1][num2] == 0)
			{
				num1--;
			}
			else
			{
				st = Up;
			}
		case Up:
			if (arr[num1][num2 - 1] == 0)
			{
				num2--;
			}
			else
			{
				st = Right;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{ 
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
