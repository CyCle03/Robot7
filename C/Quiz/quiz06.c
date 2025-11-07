#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int score1 = 0, score2 = 0, score3 = 0;

	printf("철수 : ");
	scanf("%d", &score1);

	printf("영희 : ");
	scanf("%d", &score2);

	printf("민수 : ");
	scanf("%d", &score3);

	printf("1등은 ");

	if (score1 >= score2 && score1 >= score3)
	{
		printf("철수 %d점", score1);
	}
	else if (score2 >= score3)
	{
		printf("영희 %d점", score2);
	}
	else
	{
		printf("민수 %d점", score3);
	}

	return 0;
}
