#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int price = 0, pay = 0, change = 0;

	printf("물건 가격: ");
	scanf("%d", &price);
	printf("지불 금액: ");
	scanf("%d", &pay);

	change = pay - price;

	printf("거스름돈: %d원\n", change);

	printf("1000원 %d개\n", (change / 1000));
	change %= 1000;

	printf("500원 %d개\n", (change / 500));
	change %= 500;

	printf("100원 %d개\n", (change / 100));
	change %= 100;

	return 0;
}
