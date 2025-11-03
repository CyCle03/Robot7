#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	//int kor, eng, math;
	int score[3];//score[0], score[1], score[2]
	int total = 0;
	double avg = 0.0;

	//scanf("%d", &kor);
	printf("세 과목의 성적을 입력해 주세요. : ");

	//scanf("%d", &score[0]);
	//scanf("%d", &score[1]);
	//scanf("%d", &score[2]);

	total = 0;

	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &score[i]);
		total += score[i];
	}

	printf("score[0] : %d, score[1] : %d, score[2] : %d\n", score[0], score[1], score[2]);

	//총점
	/*int total = score[0] + score[1] + score[2];*/
	//int total = 0; //지역변수는 초기화 하지 않으면 쓰레기 값이 들어가는 문제가 있다.
	//for (int i = 0; i < 3; i++)
	//{
	//	total += score[i];
	//}

	printf("총점 : %d\n", total);
	avg = (double)total / 3;
	printf("평균 : %.2lf\n", avg);

	return 0;
}