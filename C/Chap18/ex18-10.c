#include<stdio.h>

int main()
{
    FILE* fp;
    int age;
    char name[20];

    fp = fopen("a3.txt", "r");

    fscanf(fp, "%d", &age);
    while(fgetc(fp) != '\n'); //버퍼 공유 문제 처리 tip.
    fgets(name, sizeof(name), fp);

    printf("나이 : %d, 이름 : %s", age, name);
    fclose(fp);

    return 0;
}
