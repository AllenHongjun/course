/*
【例8-15-1】字符串输入输出函数的使用比较。
*/

/* 程序A：使用scanf和printf函数输入输出字符串的示例 */
#include <stdio.h>
int main( )
{
    char str[80];

    scanf("%s", str);
    printf("%s", str);
    printf("%s", "Hello");

    return 0;
}

