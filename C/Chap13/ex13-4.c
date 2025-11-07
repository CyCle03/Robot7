#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void auto_func();
void static_func();

int main()
{
	printf("일반 지역 변수(auto)를 사용한 함수...\n");
	for (int i = 0; i < 3; i++)
	{
		auto_func();
	}

	printf("정적 지역 변수(static)를 사용한 함수...\n");
	for (int i = 0; i < 3; i++)
	{
		static_func();
	}

	return 0;
}

void auto_func()
{
	auto int a = 0;

	a++;
	printf("%d\n", a);
}

void static_func()
{
	static int a;//한 번 컴파일러가 메모리를 할당 하고 나면 또 0으로 초기화 되지 않는다.

	a++;
	printf("%d\n", a);
}
