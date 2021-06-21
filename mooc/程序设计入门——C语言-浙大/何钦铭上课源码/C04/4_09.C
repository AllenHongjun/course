/*【例4-9】求100以内的全部素数，每行输出10个。素数就是只能被1和自身整除的正整数，1不是素数，2是素数。*/

/* 使用嵌套循环求100以内的全部素数 */
#include <stdio.h>
#include <math.h> 	/* 调用求平方根函数，需要包含数学库 */
int main(void)
{
    int count, i, m, n;   

    count = 0;    	          /* count记录素数的个数，用于控制输出格式 */
    for(m = 2; m <= 100; m++){
          n = sqrt(m);
          for(i = 2; i <= n; i++) 
              if(m % i == 0)  break;
          if(i > n){   		  /* 如果m是素数 */
              printf("%6d", m);   /* 输出m */
              count++;            /* 累加已经输出的素数个数 */
              if(count % 10 == 0) /* 如果count是10的倍数，换行 */
                  printf("\n");   
          }
    }
    printf("\n");

    return 0;
}
