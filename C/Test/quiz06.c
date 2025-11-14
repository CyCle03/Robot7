#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char str[80];
	int large = 0, small = 0, num = 0, special = 0;
	int size_str;

	scanf("%s", str);

	size_str = sizeof(str) / sizeof(str[0]);
	
	for (int i = 0; i < size_str; i++)
	{
		if (str[i] == '\0')
		{
			break;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			large++;
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			small++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			num++;
		}
		else
		{
			special++;
		}
	}
	
	printf("알파벳 대문자 : %d\n", large);
	printf("알파벳 소문자 : %d\n", small);
	printf("숫자 : %d\n", num);
	printf("특수문자 : %d\n", special);

	return 0;
}
