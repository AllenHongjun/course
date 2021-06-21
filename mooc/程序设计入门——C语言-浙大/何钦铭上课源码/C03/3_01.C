/*【例3-1】输入10个字符，统计其中英文字母、数字字符和其他字符的个数。*/

/* 统计字符，包括英文字母、数字字符和其他字符 */
#include <stdio.h>
int main(void)
{
   int digit, i, letter, other;     /* 定义3个变量分别存放统计结果 */
   char ch;                         /* 定义1个字符变量ch */

   digit = letter = other = 0;      /* 置存放统计结果的3个变量的初值为零 */
   printf("Enter 10 characters: "); /* 输入提示 */
   for(i = 1; i <= 10; i++){        /* 循环执行了10次 */
       ch = getchar();              /* 从键盘输入一个字符，赋值给变量 ch   这个你的代码可以在 shell里面先写完 。。但是 程序执行的时候会一个一个的执行*/
       if((ch >= 'a' && ch <= 'z' ) || ( ch >= 'A' && ch <= 'Z'))
           letter ++;                /* 如果ch是英文字母，累加letter */
       else if(ch >= '0' && ch <= '9')
    	      digit ++;              /* 如果ch是数字字符，累加digit */
       else                	
           other ++;                 /* ch是除字母、数字字符以外的其他字符，累加other */
   }
   printf("letter=%d, digit=%d, other=%d\n", letter, digit, other);

   return 0;
}


/*写写代码找找手感  不足之处  只能查找10个字符 多了话就找不到了 z*/

int test(void){
	int digit,i,letter,other;
	char ch;
	digit = letter = other = 0;
	printf("Enter 10 charactoers:f ");
	for(i = 1; i <= 10; i++ ){
		ch = getchar();
		if((ch >= 'a' && ch <= 'z') || (ch >= 'A') && ch <= 'Z')
			letter ++;
		else if (ch >= '0' && ch <= '9')
			digit ++;
		else
			other ++;
		
	}
	printf("letter=%d, digit=%d, other=%d\n",letter, digit, other);

	return 0;
}