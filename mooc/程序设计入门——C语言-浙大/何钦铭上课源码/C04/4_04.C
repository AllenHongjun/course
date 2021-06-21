/*【例4-4】输入一个正整数m，判断它是否为素数。素数就是只能被1和自身整除的正整数，1不是素数，2是素数。*/

/* 判断正整数m是否为素数 */
#include <stdio.h>
int main(void)
{
    int i, m;

    printf("Enter a number: "); /* 输入提示 */
    scanf ("%d", &m);	
    for(i = 2; i <= m/2; i++)	/* 第9行 */
        if(m % i == 0)
            break; 	        /* 若m能被某个i整除，则m不是素数，提前结束循环 */
    if(i > m/2)/* 如果循环正常结束，说明m不能被任何一个i整除，则m是素数 */
        printf("%d is a prime number! \n", m);  
    else
        printf("No!\n");       	/* 第15行 */

    return 0;
}
