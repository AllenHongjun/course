/* 【【例3-7】输入1个整数，判断该数是奇数还是偶数。*/

/* 判断数字的奇偶性 */
#include <stdio.h> 
int main(void)
{
    int number;

    printf("Enter a number: ");     	/* 输入提示 */
    scanf("%d", &number);   	        /* 输入1个数 */
    if(number % 2 == 0){                /* 若number除以2的余数是0，则为偶数 */
        printf("Tne number is even. \n");
    }
    else{                               /* 若number除以2的余数不是0，则为奇数 */
        printf("Tne number is odd. \n");
    }

    return 0;
}
