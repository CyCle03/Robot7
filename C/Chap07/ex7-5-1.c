#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void fruit(int count)
{
	printf("apple\n");
	if (count == 3) return;
	fruit(count + 1);
}

int main()
{
	fruit(1);

	return 0;
}
