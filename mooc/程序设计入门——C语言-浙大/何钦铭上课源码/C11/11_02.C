/*
【例11-2】使用指针数组输出5种颜色的英文名称。*/

/* 用指针数组输出5种颜色的英文名称 */
#include <stdio.h> 
int main(void)
{
    int i;
    char *color[5] = {"red", "blue", "yellow", "green", "purple"}, *tmp;

    /* 输出字符串的地址和内容*/
    for(i = 0; i < 5; i++)
        printf("%x, %s\n", color[i], color[i]);
    /* 交换color[0]与color[4]*/
    tmp = color[0]; 
    color[0] = color[4]; 
    color[4] = tmp; 
    printf("color[0]:%s, color[4]:%s\n",color[0],color[4]);

    return 0;
}
