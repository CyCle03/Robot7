#include<stdio.h>

int main()
{
    FILE* fp;
    char str[] = "블루베리";
    int i;

    fp = fopen("truits.txt", "w");

    if(fp == NULL)
    {
        printf("파일 출력에 실패했습니다.\n");

        return 1;
    }

    i = 0;
    while(str[i] != '\0')
    {
        fprintf(fp, "%c", str[i]);
        i++;
    }

    fprintf(fp, "%c", '\n');
    fclose(fp);

    return 0;
}
