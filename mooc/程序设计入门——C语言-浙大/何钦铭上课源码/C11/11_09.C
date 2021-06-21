/*
【例11-9】输入一个字符串和一个字符，如果该字符在字符串中，就从该字符首次出现的位置开始输出字符串中的字符。例如，输入字符r和字符串program后，输出rogram。要求定义函数match(s, ch)，在字符串s中查找字符ch，如果找到，返回第一次找到的该字符在字符串中的位置（地址）；否则，返回空指针NULL。
*/

/* 查找字符串中的字符位置（指针作为函数的返回值示例）*/
#include <stdio.h> 
char *match(char *s, char ch)  	/* 函数返回值的类型是字符指针 */
{    
    while(*s != '\0')
        if(*s == ch)  
            return(s);  /* 若在字符串s中找到字符ch，返回相应的地址 */
	else
            s++;
    return(NULL);  	/* 在s中没有找到ch，返回空指针 */
}

int main(void )
{
    char ch, str[80], *p = NULL;

    printf("Please Input the string:\n"); /* 提示输入字符串 */
    scanf("%s", str);
    getchar();         			  /* 跳过输入字符串和输入字符之间的分隔符 */
    ch = getchar();  			  /* 输入一个字符 */
    if((p = match(str, ch)) != NULL)      /* 调用函数match() */
        printf("%s\n", p);
    else 
        printf("Not Found\n");
    return 0;
}
