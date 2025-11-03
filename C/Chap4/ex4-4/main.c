#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 5, b = 5;
	int pre, post;

	pre = (++a) * 3;
	post = (b++) * 3;

	printf("%d %d\n", a, b);
	printf("%d %d\n", pre, post);
	
	return 0;
}