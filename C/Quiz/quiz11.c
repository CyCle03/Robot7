#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void print_line(int number);

int main()
{
	int line = 0;

	printf("라인 수를 입력하세요.: ");
	scanf("%d", &line);

	print_line(line);
	printf("학번\t이름\t전공\t학점\t\n");
	print_line(line);

	return 0;
}

void print_line(int number)
{
	for (int i = 0; i < number; i++)
	{
		printf("-");
	}
	printf("\n");
}
