#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int ch;//getchar 자체가 글자 하나를 받아서 int로 리턴해주기 때문

	ch = getchar();//int ch = getchar();
	printf("입력한 문자 : ");
	putchar(ch);
	putchar('\n');

	return 0;
}
