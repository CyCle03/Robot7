#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 10, b = 20;

	printf("교환 전 a와 b의 값 : %d, %d\n", a, b);
	{
		int temp;
		//int a = 0, b = 0;//안에서도 a와 b를 선언하면 바깥에 나가면서 사라져 아무일도 일어나지 않는다.

		temp = a;
		a = b;
		b = temp;
	}
	printf("교환 후 a와 b의 값 : %d, %d\n", a, b);

	return 0;
}
