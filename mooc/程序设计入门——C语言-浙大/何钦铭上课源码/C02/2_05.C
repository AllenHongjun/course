/*【例2-5】计算存款的本息。输入存款金额 money、存期 year 和年利率 rate，根据公式计算存款到期时的本息合计 sum（税前），输出时保留2位小数。*/

/* 计算存款的本息 */
# include <stdio.h> 
# include <math.h>   /* 程序中调用了数学库函数，需包含头文件math.h */ 
int main(void)
{
    int money, year;                   /* 定义2个整型变量 */
    double rate, sum;                  /* 定义2个双精度浮点型变量 */

    printf("Enter money:");            /* 提示输入money */
    scanf("%d", &money);               /* 调用scanf函数输入money */
    printf("Enter year:");             /* 提示输入year */
    scanf("%d", &year);                /* 调用scanf函数输入year */
    printf("Enter rate:");             /*提示输入rate */
    scanf("%lf", &rate);               /* 调用scanf函数输入rate, %lf 中的l是字母 */
    sum = money * pow((1 + rate), year);  /* 调用幂函数pow 计算 */
    printf("sum = %.2f\n", sum); 

    return 0;
}

