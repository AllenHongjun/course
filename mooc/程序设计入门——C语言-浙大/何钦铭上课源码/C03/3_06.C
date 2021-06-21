/* 【例3-6】输入10个字符，分别统计出其中空格或回车、数字和其他字符的个数。*/

/* 统计字符，包括空格或回车、数字和其他字符 */
#include <stdio.h>
int main(void)
{
   int blank, digit, i, other;   	/* 定义3个变量分别存放统计结果   老师只是说这个提示 有的时候 可能不是那么的明确 可能是10行的错误 回显示到11行 去  但不是说 没有用 最起码 你要认真 看的懂这个错误提示*/
   char ch;                          

   blank = digit = other = 0;    	/* 置存放统计结果的3个变量的初值为零 */
   printf("Enter 10 characters: ");    	/* 输入提示 */
   for(i = 1; i <= 10; i++){            /* 循环执行了10次 */
       ch = getchar();                	/* 输入一个字符 */
       /* 在switch语句中灵活应用break */
       switch (ch) {
           case ' ' :           	/* 语句段为空，请注意空格的表示 */
           case '\n':                 
               blank ++;        	/* 2个常量表达式 ' ' 和 '\n' 共用该语句段 */
               break;            	/* 跳出switch语句 */ 
           case '0' : case '1' : case '2' : case '3' : case '4' :
           case '5' : case '6' : case '7' : case '8' : case '9' :  
               digit ++;    	        /* 10个常量表达式 '0' ～ '9' 共用该语句段*/
               break;         	        /* 跳出switch语句 */
           default:
               other ++;                /* 累加其他字符 */
               break;            	/* 跳出switch语句 */
       }   
   }
   printf("blank=%d, digit=%d, other=%d\n", blank, digit, other);

   return 0;
}
