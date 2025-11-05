#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<limits.h>

int main()
{
	int arr[6] = { 3, 7, 2, 9, 5, 1 };
	//int max = 0;
	int max = INT_MIN;
	int index = 0;

	for (int i = 0; i < 6; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			index = i;
		}
	}

	printf("max : %d\nindex : %d\n", max, index);

	return 0;
}
