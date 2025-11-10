#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void swap_ptr(char** ppa, char** ppb);

int main()
{
	char* pa = "success";//string a;
	char* pb = "failure";//string b;

	printf("pa -> %s, pb -> %s\n", pa, pb);
	swap_ptr(&pa, &pb);
	printf("pa -> %s, pb -> %s\n", pa, pb);

	return 0;
}

void swap_ptr(char** ppa, char** ppb)//(string* pa, string* pb);
{
	char* pt;//string t;

	pt = *ppa;//t = *pa;
	*ppa = *ppb;//*pa = *pb;
	*ppb = pt;//*pb = t;
}
