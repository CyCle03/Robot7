#include<stdio.h>

int main()
{
    FILE* ifp;
    FILE* ofp;
    char name [20];
    int kor, eng, math;
    int total;
    double avg;
    int res;

    ifp = fopen("a.txt", "r");// ./ -> 현재 폴더의 라는 표현. 생략 가능.
    if(ifp == NULL)
    {
        printf("입력 파일을 열지 못했습니다.\n");
        return 1;
    }

    ofp = fopen("b.txt", "w");
    if (ofp == NULL)
    {
        printf("출력 파일을 열지 못했습니다.\n");
        return 1;
    }

    while(1)
    {
        //1. a.txt 내용을 읽어오기
        
        res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);
        if(res == EOF)
        {
            break;
        }

        //2. 각 총점, 평균 구하기
        total = kor + eng + math;
        avg = total / 3.0;

        //3. b.txt에 각 학생의 총점과 평균값을 파일에 출력
        fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);
    }

    //4. 리소스 반환
    fclose(ifp);
    fclose(ofp);
    
    return 0;
}
