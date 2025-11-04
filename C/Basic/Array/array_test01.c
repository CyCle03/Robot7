#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int array[3];

	array[0] = 1;
	array[1] = 2;
	array[2] = 3;

	printf("%d %d %d\n\n", array[0], array[1], array[2]);
	///////////////////////////////////////////////////////
	for (int i = 0; i < 3; i++)
	{
		array[i] = i + 5;
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");


	return 0;
}
