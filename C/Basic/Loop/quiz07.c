#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	//1. 3단을 출력해 주세요. 
	for (int i = 1; i < 10; i++)
	{
		printf("3 * %d = %d\n", i, (3 * i));
	}

 	printf("\n");
  
	//2. 대문자 A~Z까지 소문자 a ~z까지 출력해주세요.
	char large = 'A';//char 대신 int로 해도 된다.
	char small = 'a';
  
	for (large = 'A'; large <= 'Z'; large++)
	{
		printf("%c ", large);
	}

	printf("\n");
	
	for (small = 'a'; small <= 'z'; small++)
	{
		printf("%c ", small);
	}

	return 0;
}
