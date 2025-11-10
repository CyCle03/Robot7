#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char animal[5][20];//이차원 배열은 이중 포인터

	//char** pa;
	//char* pb;
	//pa = animal;//이중 포인터
	//pb = animal[1];//단일 포인터

	int count;

	count = sizeof(animal) / sizeof(animal[0]);

	for (int i = 0; i < count; i++)
	{
		scanf("%s", animal[i]);//animal[i]는 포인터.
	}

	for (int i = 0; i < count; i++)
	{
		printf("%s, ", animal[i]);
	}

	return 0;
}
