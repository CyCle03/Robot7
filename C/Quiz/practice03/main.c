#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int number;

	printf("È¦,Â¦À» ÆÇº°ÇÒ Á¤¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
	scanf("%d", &number);

	if (number % 2 != 0)
	{
		printf("È¦¼ö\n");
	}
	else
	{
		printf("Â¦¼ö\n");
	}


	return 0;
}