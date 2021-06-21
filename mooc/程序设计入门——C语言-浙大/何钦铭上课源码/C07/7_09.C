/*【例7-9】输入一个以回车结束的字符串（少于10个字符），
它由数字字符组成，将该字符串转换成整数后输出。*/

/* 将字符串转换为整数 */

#include <stdio.h>
int main(void)
{
    int i,n;
    char s[10];
    printf("Enter a string: ");
    i = 0;
    while((s[i] = getchar() != '\n'))
        i ++;
    s[i] = '\0';

    n = 0;
    for(i = 0; s[i] !='\0'; i++)
        if(s[i] <= '9' && s[i] >= '0')
            n = n*10 + (s[i] - '0');
        else
            break;

    printf("digit = %d\n", n);

    return 0;
}

// #include <stdio.h>
// int main(void)
// {
//     int i, n;
//     char s[10];

//     /* 输入字符串 */
//     printf("Enter a string: ");  /* 输入提示 */
//     i = 0;
//     while((s[i] = getchar( )) != '\n') 
//         i++; 
//     s[i] = '\0';

//     /* 将字符串转换为整数 */
//     n = 0;
//     for(i = 0; s[i] != '\0'; i++)
//         if(s[i] <= '9' && s[i] >= '0') 
//             n = n * 10 + (s[i] - '0');
//         else        		/* 遇非数字字符结束转换 */
//             break; 
//     printf("digit = %d\n", n);

//     return 0;
// }    
