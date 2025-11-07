#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	char str[80];
	int cnt = 0;

	printf("모음의 개수를 셀 영어를 소문자로 입력하세요. : ");
	fgets(str, sizeof(str), stdin);

	for (int i = 0; i < strlen(str) ; i++)
	{
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
		{
			cnt++;
		}
	}

	printf("모음은 총 %d개 입니다.\n", cnt);

	return 0;
}
