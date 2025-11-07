#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int cer;
	double fah;

	printf("화씨온도로 변환할 섭씨온도를 입력하세요.(1~100): ");
	scanf("%d", &cer);

	fah = (double)9 / (double)5 * cer + 32;

	printf("섭씨온도 %d도는 화씨온도 %.2lf도 입니다.", cer, fah);

	return 0;
}
