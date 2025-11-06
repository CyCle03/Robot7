#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<limits.h>

void print_max(int* arr);

int main()
{
	int array[7] = { 4,5,8,1,2,3,7 };

	print_max(array);

	return 0;
}

void print_max(int* arr)
{
	int max = INT_MIN;

	for (int i = 0; i < 7; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	printf("가장 큰 값 : %d\n", max);
}
