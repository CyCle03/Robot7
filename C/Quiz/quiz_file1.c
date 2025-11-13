#include<stdio.h>

/*
    //파일을 먼저 읽고 그 다음 파일을 만들어서 써보자.
    read.txt "I CAN DO IT !!"
    write.txt "I CAN DO IT !!"
*/

int main()
{
    //1. 파일 읽기
    FILE* fin;
    char str[80];
    int ch;

    int i = 0;
    fin = fopen("read.txt", "r");
    while((ch = fgetc(fin)) != EOF)
    {
        //fputc(ch, stdout);
        str[i++] = (char)ch;
        if(i >= 80)
        {
            break;
        }
    }
    str[i] = '\0';

    fclose(fin);
    

    //2. 파일 쓰기
    FILE* fout;
    fout = fopen("write.txt", "w");
    fprintf(fout, "%s", str);

    fclose(fout);
}
