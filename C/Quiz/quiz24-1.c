#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct book
{
	char* title;
	char* author;
	int page;
	int price;
};

int main()
{
	struct book b1;

	b1.title = "C 프로그래밍";
	b1.author = "데니스";
	b1.page = 180;
	b1.price = 18000;

	printf("도서명 : %s\n", b1.title);
	printf("저자 : %s\n", b1.author);
	printf("페이지 수 : %d\n", b1.page);
	printf("가격 : %d\n", b1.price);

	return 0;
}
