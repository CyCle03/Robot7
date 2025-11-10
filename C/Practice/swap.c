#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int Swap1(int a, int b);//c에선 함수도 소문자로 시작하지만
int Swap2(int* pa, int* pb);//강조하기 위해 대문자로 시작

int main()
{
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);

	Swap1(a, b);
	printf("%d, %d\n", a, b);

	Swap2(&a, &b);
	printf("%d, %d\n", a, b);

	return 0;
}

int Swap1(int a, int b)
{
	int temp;


	temp = a;
	a = b;
	b = temp;
}

int Swap2(int* pa, int* pb)
{
	int temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
