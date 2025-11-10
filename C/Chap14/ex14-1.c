#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int score[3][4];
	int total = 0;
	double avg = 0.0;

	for (int i = 0; i < 3; i++)
	{
		printf("4과목의 점수 입력 : ");
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &score[i][j]);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		total = 0;
		for (int j = 0; j < 4; j++)
		{
			total += score[i][j];
		}
		avg = total / 4.0;
		
		printf("총점 : %d, 평균 : %.2lf\n", total, avg);
	}

	return 0;
}
