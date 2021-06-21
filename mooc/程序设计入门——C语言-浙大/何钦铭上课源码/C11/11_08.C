/*
【例11-8】所谓藏头诗，就是将这首诗每一句的第一个字连起来，所组成的内容就是该诗的真正含义。编写一个程序，输入一首藏头诗（假设只有4句），输出其真实含义。*/

/* 解密藏头诗（指针作为函数的返回值示例）  */
#include <stdio.h>
char *change(char s[ ][20], char t[ ]);
int main(void)
{
    int i;
    char s[4][20], t[10], *p;
    printf("请输入藏头诗：\n");
    for(i = 0; i < 4; i++)
        scanf("%s", s[i]);
    p = change(s, t);
    printf("%s\n", p);

    return 0;
}
char * change(char s[ ][20], char t[ ])
{
    int i;

    for(i= 0; i < 4; i++) {
        t[2*i] = s[i][0];
        t[2*i+1] = s[i][1];
    }
    t[2*i] = '\0';

    return t;
}
