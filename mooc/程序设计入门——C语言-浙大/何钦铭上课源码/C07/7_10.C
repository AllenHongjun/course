/*【例7-10】计算字符串的有效长度，
并输出该字符串。字符串的有效长度就是有效字符的个数，
即数组中第1个 '\0' 前面的字符个数。*/

/* 计算字符串的有效长度 */

#include <stdio.h>
int main(void)
{
    int i = 0, len;
    char str[80] = "Happy"; //{'a','b','c','d','\0'}

    for (i = 0; str[i] != '\0'; i++)
        ;
    len = i;
    printf("len = %d\n", len);

    for (i = 0; str[i] != '\0'; i++)
        putchar(str[i]);
    return 0;
}
// 文件 指针的高级应用。 格式化支付串输出的格式。。标准库里面的函数的使用。。需要为后续的学习打下基础。
//还需要多看一些代码。
// #include <stdio.h>
// int main(void)
// {
//     int i = 0, len;
//     char str[80] = "Happy";  	     /* 用字符串常量初始化字符数组 */

//     /* 计算字符串的有效长度 */
//     for(i = 0; str[i] != '\0'; i++)  /* 循环条件：数组元素 str[i] 不等于 '\0' */
//         ;                            /* for的循环体语句为空   人家一完小小时在写 C++  你看看你写了多少代码*/

//     len = i;
//     printf("len = %d\n", len);

//     /* 输出字符串 */
//     for(i = 0; str[i] != '\0'; i++)
//         putchar(str[i]);

//     return 0;
// }
