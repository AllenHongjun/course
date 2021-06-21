/*
【例11-6】输入一些球的颜色，以#作为输入结束标志，再输出这些颜色。其中颜色数小于20，颜色的英文名称不超过10个字符（用动态分配内存的方法处理多个字符串的输入示例）。
*/

/* 用动态分配内存方法处理多个字符串的输入  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int i, n = 0;
    char *color[20], str[10];
    printf("请输入颜色名称，每行一个，#结束输入：\n");
    scanf("%s", str);
    while(str[0] != '#') {
        color[n] = (char *)malloc(sizeof(char)*(strlen(str)+1));  
        strcpy(color[n], str);
	        n++;
        scanf("%s", str);
    }
    printf("你输入的颜色是：");
    for(i = 0; i < n; i++)
        printf("%s  ", color[i]);

    return 0;
}
