/*
【例11-8】所谓藏头诗，就是将这首诗每一句的第一个字连起来，所组成的内容就是该诗的真正含义。编写一个程序，输入一首藏头诗（假设只有4句），输出其真实含义。*/

/* 解密藏头诗（指针作为函数的返回值示例）  */
#include <stdio.h>
#include <stdlib.h>
char *change_d(char s[ ][20]);
int main(void)
{
    int i;
    char s[4][20], *p = NULL;

    printf("请输入藏头诗：\n");
    for(i = 0; i < 4; i++)
        scanf("%s", s[i]);
    p = change_d(s);
    printf("%s\n", p);

    return 0;
}

char * change_d(char s[ ][20])
{
    int i;
    char *head, *p;

    if((p = (char *)calloc(8, sizeof(char))) == NULL){
        printf("Unable to allocate memory\n");
        exit(1);
    }
    head = p;
    for(i= 0; i < 4; i++) {
        *(p++) = s[i][0];
        *(p++) = s[i][1];
    }
    *p = '\0';

    return head;
}