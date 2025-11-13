#include<stdio.h>
#include<string.h>

int main()
{
    FILE* ifp;
    FILE* ofp;
    char str[80];
    char* res;

    ifp = fopen("a1.txt", "r");
    if(ifp == NULL)
    {
        printf("입력 파일을 열지 못했습니다.\n");
        return 1;
    }

    ofp = fopen("b1.txt", "w");
    if(ofp == NULL)
    {
        printf("출력 파일을 열지 못했습니다.\n");
        return 1;
    }

    while(1)
    {
        res = fgets(str, sizeof(str), ifp);

        if(res == NULL)
        {
            break;
        }
        str[strlen(str) - 1] = '\0';
        fputs(str, ofp);//b1.txt에 한 줄 write
        fputs(" ", ofp);
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}
