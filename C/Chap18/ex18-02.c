#include<stdio.h>

int main()
{
    FILE *fp;
    int ch;

    fp = fopen("a.txt", "r");
    if(fp == NULL)
    {
        printf("파일이 열리지 않았습니다.\n");
        return 1;
    }

    while (1)//무한루프
    {
        ch = fgetc(fp);//한 글자를 가져오는 함수
        if(ch == EOF)//EOF == -1(파일의 끝)
        {
            break;
        }
        putchar(ch);
    }
    fclose(fp);//자원(resource) 반납, 반환

    return 0;
}
