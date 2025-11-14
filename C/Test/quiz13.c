#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int arr[7];
	int temp = 0;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 7; i++)
	{
		arr[i] = rand() % 45 + 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				i--;
			}
		}
	}

	for (int i = 5; i > 0 ; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}


	printf("로또 번호 : ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("보너스 번호 : %d\n", arr[6]);


	return 0;
}
