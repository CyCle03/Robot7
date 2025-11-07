#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char ch;

	printf("문자 입력 : ");
	ch = getchar();
	printf("%c문자의 아스키 코드 값 : %d\n", ch, ch);

	return 0;
}
