#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

double average(int num1, int num2, int num3, int num4);

int main()
{
	int num_a, num_b, num_c, num_d;

	printf("1에서 100 사이의 자연수를 네 개 입력하세요: ");
	scanf("%d %d %d %d", &num_a, &num_b, &num_c, &num_d);

	printf("자연수 %d, %d, %d, %d의 평균은 %.2lf 입니다.\n", num_a, num_b, num_c, num_d, average(num_a, num_b, num_c, num_d));

	return 0;
}

double average(int num1, int num2, int num3, int num4)
{
	double result = (double)(num1 + num2 + num3 + num4) / 4;

	return result;
}
