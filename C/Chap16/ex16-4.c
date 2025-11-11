#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char temp[80];
	char* str[3];

	for (int i = 0; i < 3; i++)
	{
		printf("문자열을 입력하세요 : ");
		fgets(temp, sizeof(temp), stdin);//gcc에는 gets가 없다.
		str[i] = (char*)malloc(strlen(temp) + 1);//+1 '\n'문자
		strcpy(str[i], temp);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", str[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		free(str[i]);
	}

	return 0;
}
