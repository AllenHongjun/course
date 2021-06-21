/*【例6-11】输入一个以回车结束的字符串（少于80个字符），统计其中数字字符的个数。*/

/* 统计字符串中数字字符的个数 */
#include <stdio.h>
int main(void)
{
    int count ,i;
    char str[80];
    printf("Enter a string:");
    i = 0;
    while((str[i] = getchar() != '\n'))
        i ++;
    str[i] = '\0';
    count = 0;

    for(i = 0; str[i] !='\0'; i++)
        if(str[i] <= '9' && str[i] >= '0')
            count ++;

    printf("count = %d\n",count);
    return 0 ;
}


// #include <stdio.h>
// int main(void)
// {
//     int count, i;
//     char str[80];

//     /* 输入字符串 */
//     printf("Enter a string: ");       /* 输入提示 */
//     i = 0;
//     while((str[i] = getchar( )) != '\n') 
//         i++; 
//     str[i] = '\0';                     将结束符 '\0' 存入数组 

//     /* 统计字符串中数字字符的个数 */
//     count = 0;
//     for(i = 0; str[i] != '\0'; i++)   /* 循环条件：数组元素 str[i] 不等于 '\0' */
//         if(str[i] <= '9' && str[i] >= '0') 
//             count++;
//     printf("count = %d\n", count);

//     return 0;
// }   


// int test(void)
// {
//     int count,i;
//     char str[80];
//     printf("Enter a string: ");
//     i=0;
//     while((str[i]=getchar())!='\n')
//         i++;
//     str[i]='\0';
//     count =0;
//     for(i=0;str[i]!='\0';i++)
//         if(str[i]<='9'&&str[i]>='0')
//             count++;
//     printf("count = %d\n",count );
//     return 0;
// } 
