#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "student.h" //사용자 정의 헤더를 가져오려면 쌍따옴표를 사용.

int main()
{
	Student hong = { 315, "홍길동" };

	printf("학번 : %d 이름 : %s\n", hong.num, hong.name);

	return 0;
}
