/*
【例8-15-2】字符串输入输出函数的使用比较。
*/

/* 程序B：使用gets和puts函数输入输出字符串的示例*/
#include <stdio.h>
int main( )
{ 
    char str[80];

    gets(str);
    puts(str);
    puts("Hello");

    return 0;
}     


