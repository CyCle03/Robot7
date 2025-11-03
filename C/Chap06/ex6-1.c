#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i = 1;

	while (i < 20)
	{
		i *= 2;//index값에 대한 증가감

		printf("i : %d\n", i);
	}
	
	printf("end of i : %d\n", i);

	return 0;
}
