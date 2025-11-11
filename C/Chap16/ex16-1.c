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

	pi = (int*)malloc(sizeof(int));
	printf("Heap\n%p\n", pi);
	printf("Stack\n%p\n%p\n", &a, &b);
	printf("String\n%p\n", "hello");
	printf("Global\n%p\n", &total);

	return 0;
}
