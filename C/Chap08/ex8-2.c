#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int score[5];
	int total = 0;
	double avg = 0;

	for(int i = 0; i < 5; i++)
	{
		scanf("%d", &score[i]);
	}

	//total = score[0] + score[1] + score[2] + score[3] + score[4];
	for (int i = 0; i < 5; i++)
	{
		//total = total + score[i];
		total += score[i];
	}

	avg = total / 5.0;

	for (int i = 0; i < 5; i++)
	{
		printf("%5d", score[i]);
	}
	printf("\n");

	printf("평균 : % .1lf\n", avg);

	return 0;
}
