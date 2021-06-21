/*【例4-6】计算1! + 2! + 3! + … + 100!。要求使用嵌套循环。*/

/* 使用嵌套循环计算 1! + 2! + 3! + … + 100! */
#include <stdio.h>
void main( )
{
    int i, j;
    double item, sum;     /* 变量 item 中存放阶乘的值 */

    sum = 0;
    for(i = 1; i <= 100; i++){        /* 外层循环执行100次，求累加和 */
        item = 1;    /* 置 item 的初值为1，以保证每次求阶乘都从1开始连乘 */
        for (j = 1; j <= i; j++)      /* 内层循环重复i次，算出item = i! */
            item = item * j;
        sum = sum + item;             /* 把 i! 累加到sum中 */
    }
    printf("1! + 2! + ... + 100! = %e\n", sum); /* 用指数形式输出结果 */

    return 0;

    //吃完饭 继续来调试这个代码
}


test main()
{
    int i, j;
    double item ,sum;
    sum =0;
    for (int i = 0; i <=100; ++i)
    {               
        item =1;
        for (int i = 0; i < i-1; ++i)
        {
            item = item *j;         
        }
        sum = sum + item;
    }
    printf("1! +2! +3! + ... +100! = %e\n", sum);

    return 0;

    //有可能你已经喜欢上了 某人 但是你自己却不知道

}
