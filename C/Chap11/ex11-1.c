#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char small;
	char cap = 'G';

	if ((cap >= 'A') && (cap <= 'Z'))
	{
		small = cap + ('a' - 'A');
	}
	printf("대문자 : %c %c", cap, '\n');
	printf("소문자 : %c", small);

	return 0;
}
