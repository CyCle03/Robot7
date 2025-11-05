#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int ary[5];

	ary[0] = 10;
	ary[1] = 20;
	ary[2] = ary[0] + ary[1];//10 + 20
	
	scanf("%d", &ary[3]);//50

	printf("ary[2] : %d\n", ary[2]);//30
	printf("ary[3] : %d\n", ary[3]);//50
	printf("ary[4] : %d\n", ary[4]);//쓰레기 값

	return 0;
}
