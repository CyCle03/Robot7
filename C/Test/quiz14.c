#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int menu = 0;
	while (1)
	{
		printf("1. 데이터 삽입\n");
		printf("2. 데이터 삭제\n");
		printf("3. 데이터 조회\n");
		printf("4. 데이터 수정\n");
		printf("5. 프로그램 종료\n");
		printf("\n");

		printf("메뉴 : ");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			printf("프로그램이 종료됩니다.\n");
			return 0;
		default:
			printf("잘못 입력하셨습니다. \n");
			break;
		}
	}

	return 0;
}
