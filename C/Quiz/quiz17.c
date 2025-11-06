#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char arr[80];
	int cap = 0, small = 0, num = 0, special = 0;

	scanf("%s", arr);

	for (int i = 0; i < 80; i++)
	{
		if (arr[i] == NULL)
		{
			break;
		}
		else if (arr[i] >= 'A' && arr[i] <= 'Z')
		{
			cap++;
		}
		else if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			small++;
		}
		else if (arr[i] >= '0' && arr[i] <= '9')
		{
			num++;
		}
		else
		{
			special++;
		}
	}

	printf("알파벳 대문자 : %d\n알파벳 소문자 : %d\n숫자 : %d\n특수문자 : %d\n", cap, small, num, special);

	return 0;
}
