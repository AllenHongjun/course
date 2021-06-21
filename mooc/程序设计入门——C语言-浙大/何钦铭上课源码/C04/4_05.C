/*【例4-5】计算1! + 2! + 3! + … + 100!。要求定义和调用函数fact(n)计算n的阶乘。*/

/* 使用函数计算 1! + 2! + 3! + … + 100! */
#include <stdio.h>
double fact (int n);		/* 函数声明  就把函数的定义的头部拿过来 加一个分号 然后放到开始的地方*/
int main(void)
{
    int i;
    double sum;

    sum = 0;
    for(i = 1; i <= 100; i++ )
        sum = sum + fact (i);		/* 调用fact(i)求i!，共重复100次 */
    printf("1! + 2! + ... + 100! = %e\n", sum); /* 用指数形式输出结果 */

    return 0;
}

/* 定义求 n! 的函数 */
double fact (int n)
{
    int i;			 
    double result;   	        /* 变量 result 中存放阶乘的值 */

    result = 1;      	        /* 置阶乘 result 的初值为1 */
    for(i = 1; i <= n; i++)  	/* 循环执行n次，计算n! */
        result = result * i;

    return  result;      	/* 把结果回送主函数 */
}
