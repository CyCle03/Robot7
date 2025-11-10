#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void print_str(char** pps, int cnt);

int main()
{
	//char ptr_arr[4][10];//문자열 배열 상수
	//char* ptr_ary[4] = { "eagle", "tiger", "lion", "squirrel" };
	char* ptr_ary[] = { "eagle", "tiger", "lion", "squirrel" };
	
	//char** ptr_ary = { "eagle", "tiger", "lion", "squirrel" };//error
	char** ptr_ary3 = (char*[]){ "eagle", "tiger", "lion", "squirrel" };//(char*[])로 캐스팅 하면 가능하다.

	int count = sizeof(ptr_ary)/ sizeof(ptr_ary[0]);//4

	print_str(ptr_ary, count);

	return 0;
}

void print_str(char** pps, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		printf("%s\n", pps[i]);
	}
}
