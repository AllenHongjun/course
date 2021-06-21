/*
【例11-3】改写例10-1，要求使用指向指针的指针。
*/

/* 功能：布袋中的彩色球（使用指向指针的指针）*/
#include<stdio.h>
int main(void)
{
    char *color[5] = {"red", "blue", "yellow", "green", "purple"};
    char **pc = color;
    int count = 0, i, j;  

    for(i = 0; i <= 3; i++)
        for(j = i+1; j <= 4; j++) {
            if(i == j)  continue;
            count++;
            printf("%6d", count);
            printf("%10s %10s\n", *(pc+i), *(pc+j));
    }

    return 0;
}
