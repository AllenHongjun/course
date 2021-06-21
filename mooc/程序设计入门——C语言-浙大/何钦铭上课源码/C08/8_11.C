/*
【例8-11】输入10个整数作为数组元素，计算并输出它们的和。
*/


//下次从指针作为 函数的参数开始  计算机导论 离散数学  c语言 英语 高数先修课 这几门入手
/*  使用指针计算数组元素之和 */
#include <stdio.h>
int main(void)
{
    int i, a[10], *p;
    long sum = 0;

    printf("Enter 10 integers: ");
    for(i = 0; i < 10; i++) 
        scanf("%d", &a[i]);
    for(p = a; p <= a+9; p++)       /* 求和  这里没有说 数组 也是执政  把a[0]的地址赋值给了 p */
        sum = sum + *p;
    printf("sum=%ld \n", sum);

    return 0;
	1

}    
