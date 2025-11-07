#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void swap(int* pa, int* pb);

int main()
{
	int a = 0, b = 0;

	printf("Swap 할 정수 두 개(a, b)를 입력하세요 : ");
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("(a, b) : (%d, %d)\n", a, b);

	return 0;
}

void swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}
