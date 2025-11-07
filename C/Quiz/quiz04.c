#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int score[3], total;
	double avg;

	printf("세 과목의 성적을 입력하세요. \n");

	scanf("%d", &score[0]);
	scanf("%d", &score[1]);
	scanf("%d", &score[2]);

	total = score[0] + score[1] + score[2];
	avg = (double)total / (double)3;

	printf("총점 : %d\n", total);
	printf("평균 : %.2lf\n", avg);

	return 0;
}
