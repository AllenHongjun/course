/*
【例11-1】已知一个不透明的布袋里装有
红、蓝、黄、绿、紫
同样大小的圆球各一个，
现从中一次抓出两个，问可能抓到的是什么颜色的球？
*/

/* 布袋中的彩色球（用指针数组实现）*/
#include<stdio.h>
int main(void)
{   
    //char 数组里面只能存放一个字符吗
    char *color[5] = {"red", "blue", "yellow", "green", "purple"};  /* 初始化 */
    int count = 0, i, j;  

    for(i = 0; i <= 3; i++)          /* i代表第一个球对应的颜色下标 */
        for(j = i+1; j <= 4; j++) {   /* j代表第二个球对应的颜色下标 */
        if(i == j)  continue;   /* 两个球不能同色 */
        count ++;
        printf("%6d", count);
        printf("%10s %10s\n", color[i], color[j]);
    }

      return 0;
}
