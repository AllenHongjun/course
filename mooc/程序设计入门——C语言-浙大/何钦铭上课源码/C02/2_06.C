/*【例2-6】输入2个整数lower和 upper，输出一张华氏－摄氏温度转换表，华氏温度的取值范围是[lower, upper]，每次增加1°F。*/

/* 输出华氏－摄氏温度转换表，华氏温度取值[lower,upper]，每次增加1°F */
#include <stdio.h>
int main(void)
{    
   /* fahr表示华氏度, celsius为摄氏度,lower为华氏温度下限,upper为上限 */
   int fahr, lower, upper;
   double celsius;   

   printf("Enter lower:");           /* 输入提示 */
   scanf("%d", &lower);               /* 调用scanf函数输入lower */
   printf("Enter upper:");           /* 输入提示 */
   scanf("%d", &upper);               /* 调用scanf函数输入upper */
   printf("fahr  celsius\n");        /* 输出温度转换表的表头 */

   /* 温度重复转换：华氏温度从lower开始，到upper结束，每次增加1°F */
   for (fahr = lower ; fahr <= upper; fahr ++){ 
      celsius = (5.0 / 9.0) * (fahr - 32);        /* 温度转换计算 */
      printf("%d%6.1f\n", fahr, celsius);        /* 输出 */
   }                                              	    

   return 0;
}

