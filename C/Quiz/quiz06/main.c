#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int score1 = 0, score2 = 0, score3 = 0;

	printf("Ã¶¼ö : ");
	scanf("%d", &score1);

	printf("¿µÈñ : ");
	scanf("%d", &score2);

	printf("¹Î¼ö : ");
	scanf("%d", &score3);

	printf("1µîÀº ");

	if (score1 >= score2 && score1 >= score3)
	{
		printf("Ã¶¼ö %dÁ¡", score1);
	}
	else if (score2 >= score3)
	{
		printf("¿µÈñ %dÁ¡", score2);
	}
	else
	{
		printf("¹Î¼ö %dÁ¡", score3);
	}

	return 0;
}