#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void print_ary(int* pa);

int main()
{
	int ary[5] = { 10,20,30,40,50 };

	print_ary(ary);//배열을 함수로 전달했다.

	return 0;
}

void print_ary(int* pa)
{
	//전달받은 배열을 함수에서 출력해보자.

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", pa[i]);
	}
}
