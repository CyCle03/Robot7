#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void print_char(char ch, int count);

int main()
{
	print_char('@', 5);
	printf("\n");

	return 0;
}

void print_char(char ch, int count)
{

	for (int i = 0; i < count; i++)
	{
		printf("%c", ch);
	}

}
