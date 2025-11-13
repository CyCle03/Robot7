#include<stdio.h>

int main()
{
    int ch;

    while(1)
    {
        ch = fgetc(stdin);//ch = getchar();

        if(ch == EOF)//wsl ubuntu ^Z --> ^C로 종료
        {
            break;
        }
        fputc(ch, stdout);//putchar(ch);
    }

    return 0;
}
