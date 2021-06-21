/*【例5-5】求100以内的全部素数，每行输出10个。素数就是只能被1和自身整除的正整数，1不是素数，2是素数。要求定义和调用函数prime(m)判断m是否为素数，当m为素数时返回1，否则返回0。*/

/* 使用函数求100以内的全部素数 */

#include <stdio.h>
#include <math.h>
int main(void)
{
    int count,m;
    int prime(int m);
    count = 0;

    for(m = 2;m <= 5000; m++){
        if (prime(m))
        {
            printf("%6d",m);
            count++;
            if (count%10 ==0)
            {
                printf("\n");
            }
        }
    }
    printf("\n");
}

int prime(int m)
{
    int i,n;
    if(m ==1) return 0;
    n = sqrt(m);
    for(i =2; i<= n ;i++){
        //遍历从i到 n所有的数字 如果有一个能被m整除 那么m就不是素数 否则就是素数
        if(m % i == 0){
            return 0;
        }
    }
    return 1;
}





