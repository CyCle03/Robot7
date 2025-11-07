#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	//int age;
	char strAge[10];
	char name[20];

	printf("나이 입력 : ");
	//scanf("%d", &age);
	fgets(strAge, sizeof(strAge), stdin);
	int age = atoi(strAge);

	printf("이름 입력 : ");
	//gets(name);
	fgets(name, sizeof(name), stdin);
	printf("나이 : %d, 이름 : %s\n", age, name);

	return 0;
}
