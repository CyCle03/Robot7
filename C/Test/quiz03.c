#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int N = 0;
	char grade = 'F';

	printf("N? ");
	scanf("%d", &N);

	if (N <= 100 && N >= 90)
	{
		grade = 'A';
	}
	else if (N >= 80)
	{
		grade = 'B';
	}
	else if (N >= 70)
	{
		grade = 'C';
	}
	else if (N >= 60)
	{
		grade = 'D';
	}
	else
	{
		grade = 'F';
	}
	printf("%c학점입니다.\n", grade);

	return 0;
}
