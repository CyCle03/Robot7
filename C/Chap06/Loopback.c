#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	//1~100 더하면 누적합이 5050이 됩니다. 이를 for문으로 작성.
	int sum = 0;

	for (int i = 0; i < 100; i++)//for(int i = 1; i <= 100 ; i++) sum += i;
	{
		sum += i + 1;
		//printf("sum : %d, i ; %d\n", sum, i + 1);
	}
	
	printf("1 ~ 100의 누적 합 : %d\n", sum);

	return 0;
}
