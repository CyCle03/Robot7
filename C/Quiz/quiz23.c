#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void print_array(char** arr);

int main()
{
	char* arr[3] = { "Lion", "Tiger", "Rabbit" };
	print_array(arr);

	return 0;
}

//Q22의 char 대신 문자열을 출력
void print_array(char** arr)
{
	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", arr[i]);
	}
}
