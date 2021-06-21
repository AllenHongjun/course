/*【例7-4】输入一个正整数n (1＜n≤10)，再输入n个整数，将它们存入数组a中。
（1）输出最小值和它所对应的下标。
（2）将最小值与第1个数交换，输出交换后的n个数。
*/

/* 找出数组的最小值和它所对应的下标   b不要觉得自己有多么的了不起  也不要觉得自己多么的不行。
教育  mooc的形式 热爱  帮助   有搞头 怎么搞 如何搞。

*/

#include <stdio.h>
int main(void)
{
    int i,index,n;
    int a[10];
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter %d integers: ", n);
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    index = 0; //穷举法找出最小的那个数字的下标
    for(i = 1 ; i<n;i++)
    {
        if(a[i] <a[index])
            index = i;
    }
    printf("min is %d \t sub is %d\n",a[index],index);

}


// #include <stdio.h>
// int main(void)
// {
//     int i, index, n;
//     int a[10];    

//     printf("Enter n: ");            	/* 提示输入n */
//     scanf("%d", &n);
//     printf("Enter %d integers: ", n); 	/* 提示输入n 个数 */
//     for(i = 0; i < n; i++)  
//         scanf("%d", &a[i]);
//    /* 找最小值a[index] */
//     index = 0;           	/* 假设a[0]是最小值，即下标为0的元素最小 */
//     for(i = 1; i < n; i++)  
//         if(a[i] < a[index]) 	/* 如果 a[i] 比假设的最小值还小 */
//             index = i;   	/* 再假设 a[i] 是新的最小值，即下标为 i 的元素最小 */
//     /* 输出最小值和对应的下标 */
//     printf("min is %d\tsub is %d\n", a[index], index);   /* 第19行 */

//     return 0;
// }    

//C语言 更加贴近系统的底层  或者 很多用的地方  比如 java php .net的运行环境 Linux 系统  排序 求最大值 最小值 什么的
