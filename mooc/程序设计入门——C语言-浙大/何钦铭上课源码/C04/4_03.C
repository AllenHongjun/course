/*【例4-3】从键盘读入一个整数，统计该数的位数。例如，输入12534，输出5；输入-99，输出2；输入0，输出1。*/

/* 统计一个整数的位数 */
#include <stdio.h>
int main(void)
{    
    int count, number;       	/* count 记录整数number的位数 */

    count = 0;
    printf("Enter a number:");        /* 输入提示 */
    scanf ("%d", &number);
    if(number < 0) number = -number;  /* 将输入的负数转换为正数 */
    do{	                    			
        number = number / 10; 	      /* 整除后减少一位个位数，组成一个新数 */
        count ++;		      /* 位数加1 */
    }while(number != 0);	      /* 判断循环条件 */
    printf("It contains %d digits.\n", count);

    return 0;
}
