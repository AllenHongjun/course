/*【例5-7】全局变量定义。*/

#include "stdio.h"
int x;					/* 定义全局变量x */
int f( )
{ 
    int x = 4;			/* x为局部变量，在本函数中，全局变量x不起作用 */

    return x;
}
int main(void)
{
    int a = 1;  

    x = a;   			/* 对全局变量 x 赋值1 */
    a = f( );  			/* a的值为4 */
    {
        int b = 2; 
    	b = a + b;		/* b的值为4 */
    	x = x + b;		/* 全局变量运算 a=4  x=7*/ 
    }
    printf("%d %d" , a, x );

    return 0;
}


