#include <stdio.h>
int main(void)
{    
   int fahr , lower, upper;  /* fahr表示华氏度 */
   double celsius;        /* celsius表示摄氏度 */ 

    lower = 30; 		/* 变量 lower 给定转换范围的下限 */
    upper = 40; 		/* 变量 upper 给定转换范围的上限 */
    printf("fahr  celsius\n");             /* 显示表头 */

  /* 温度转换 */
   for (fahr = lower , fahr <= upper, fahr ++) 
    ;
      celsius = 5 /9 * (fahr - 32.0); 
      printf("%3.0f %6.1f\n", fahr, celsius); 

   return 0; 
}


