#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int arr[5];

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 5; i++)
	{
		arr[i] = rand() % 10 + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	

	return 0;
}
