#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a;
	int* pa;

	pa = &a;//a변수의 시작 주소를 pa에 넣는다.(int*)
	*pa = 10;

	printf("pa변수의 주소값 : %p\n", &pa);
	printf("a변수의 주소값 : %p\n", &a);
	printf("pa변수의 값 : %p\n\n", pa);

	printf("포인터로 a 값 출력 : %d\n", *pa);
	printf("변수명으로 a 값 출력 : %d\n", a);

	return 0;
}
