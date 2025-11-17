#include<stdio.h>

int main()
{
    FILE* ifp;
    FILE* ofp;
    char name[20];
    int kor, eng, math;
    int total;
    double avg;
    int res;

    ifp = fopen("a2.txt", "r");
    if(ifp == NULL)
    {
        printf("입력 파일이 없습니다.\n");

        return 1;
    }

    ofp = fopen("b2.txt", "w");
    if(ofp == NULL)
    {
        printf("출력 파일이 없습니다.\n");

        return 1;
    }

    while(1)
    {
        res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);
        if(res == EOF)
        {
            break;
        }

        total = kor + eng + math;
        avg = total / 3.0;

        fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}
