#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int score[3] = {0};
	int total = 0;
	double avg = 0.0;

	printf("세 과목의 성적을 입력해주세요.: ");
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &score[i]);
		total += score[i];
		printf("score[%d] = %d ", i, score[i]);
	}
	printf("\n");

	avg = (double)total / 3;

	printf("총점: %d, 평균: %.2lf\n", total, avg);

	return 0;
}
