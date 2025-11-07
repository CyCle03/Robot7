#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 20, b = 10;

	if (a > 0)
	{
		if (b >= 0)
		{
			b = 1;
		}
		else
		{
			b = -1;
		}//end of if
	}//end of if

	printf("a : %d, b : %d\n", a, b);

	b = -1;

	if (a > 0)
	{
		if (b >= 0)
		{
			b = 1;
		}
		else
		{
			b = -1;
		}//end of if
	}//end of if

	printf("a : %d, b : %d\n", a, b);

	return 0;
}//end of main
