/*【例4-1】使用格里高利公式求π的近似值，要求精确到最后一项的绝对值小于10-5。*/
                
/*  用格里高利公式计算π的近似值，精度要求：最后一项的绝对值小于0.0001  */
#include <stdio.h>
#include <math.h>      	  /* 程序中调用绝对值函数 fabs，需包含 math.h */
int main(void)
{
   int denominator, flag; 
   double item, pi;    	  /* pi 用于存放累加和 */

   /* 循环初始化 */
   flag = 1;       	  /*  flag 表示第 i 项的符号，初始为正 */
   denominator = 1;       /* denominator表示第 i 项的分母，初始为1 */
   item = 1.0;        	  /*  item 中存放第 i 项的值，初值取 1 */
   pi = 0;            	  /* 置累加和 pi 的初值为0 */

   /*  当|item| ≥ 0.0001时，执行循环 */
   while(fabs(item) >= 0.0001){   
       item = flag * 1.0 / denominator;  /* 计算第 i 项的值 */
       pi = pi + item;    /* 累加第 i 项的值 */
       flag = -flag;   	  /*  改变符号，为下一次循环做准备 */
       denominator = denominator + 2;   /* 分母递增2 ，为下一次循环做准备 */
}
   pi = pi * 4;       	  /* 循环计算的结果是 pi/4 */
   printf ("pi = %f\n", pi);

   return 0;
}
