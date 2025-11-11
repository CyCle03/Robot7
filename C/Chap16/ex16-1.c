#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>//malloc
#include<memory.h>//malloc

int total;

int main()
{
	int* pi;
	double* pd;
	int a, b;

	pi = (int*)malloc(sizeof(int));//malloc(4)
	printf("Heap\n%p\n", pi);
	printf("Stack\n%p\n%p\n", &a, &b);
	printf("String\n%p\n", "hello");
	printf("Global\n%p\n", &total);

	printf("\n");

	if (pi == NULL)//NULL 0
	{
		printf("# 메모리가 부족합니다.\n");
		exit(1);
	}

	pd = (double*)malloc(sizeof(double));//malloc(8)

	*pi = 10;//stack 메모리가 아닌
	*pd = 3.4;//Heap 메모리 공간에 값 삽입

	printf("%d\t%.2lf\n", *pi, *pd);

	free(pi);
	free(pd);

	return 0;
}
