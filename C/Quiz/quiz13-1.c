#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int arr[10] = { 0 };

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 != 0)
		{
			printf("%d ", arr[i]);
		}
	}

	return 0;
}
