#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char str[80];

	printf("공백이 포함된 문자열 입력 : ");
	//gets(str);
	fgets(str, 80, stdin);
	printf("입력한 문자열은 %s입니다.\n", str);

	return 0;
}
