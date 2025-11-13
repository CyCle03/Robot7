#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE* fin;
    FILE* fout;
    int ch;

    fin = fopen("read.txt", "r");
    if(fin == NULL)
    {
        printf("read.txt가 열리지 않았습니다.");
        exit(1);
    }
    fout = fopen("write.txt", "w");

    //fgetc가 자동으로 다음 바이트 위치로 넘긴다.
    while((ch = fgetc(fin)) != EOF)
    {
        fputc(ch, fout);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
