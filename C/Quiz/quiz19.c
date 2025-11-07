#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	char str[80];

	printf("뒤집어서 출력할 문자열을 입력해주세요 : ");
	fgets(str, sizeof(str), stdin);

	for (int i = strlen(str); i >= 0 ; i--)
	{
		printf("%c", str[i]);
	}
	printf("\n");

	return 0;
}
