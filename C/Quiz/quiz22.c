#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void print_array(char* ch);

int main()
{
	char arr[5] = { 'A', 'B', 'C', 'D', 'E' };// { "ABCDE" };

	print_array(arr);

	return 0;
}

void print_array(char* ch)
{
	//int cnt = sizeof(ch) / sizeof(ch[0]);
	//main에서 계산해 넘겨주어야 함.
	//포인터 / 캐릭터가 되기 때문에

	for (int i = 0; i < 5; i++)
	{
		printf("%c ", ch[i]);
	}
}
