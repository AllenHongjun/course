/*【例5-2】输出5之内的数字金字塔。*/

#include <stdio.h>
int main(void)
{
	void pyramid(int n);

	pyramid(99);
	return 0;
}

void pyramid(int n)
{
	int i, j;
	for(i = 1; j <= n; i++){
		for(j =1; j<=n-i;j++)
			printf(" ");
		for(j = 1;j <=i; j++)
			printf(" %d ",i);
		putchar('\n');
	}
}





// /* 输出数字金字塔 */
// #include <stdio.h>
// int main(void)
// {   
// 	void pyramid(int n);					/* 函数声明 */

// 	pyramid(5);								/* 调用函数，输出数字金字塔 */
// 	return 0;
// }

// void pyramid(int n)							/* 函数定义 */
// {		
// 	int i, j;

// 	for(i = 1; i <= n; i++){				 需要输出的行数 
// 		for(j = 1; j <= n-i; j++) 			/* 输出每行左边的空格 */
// 			printf(" ");		        
// 		for(j = 1; j <= i; j++)  			/* 输出每行的数字 我想学的这个专业叫做计算机 叫做软件工程 这都没有搞清楚  什么高大上的电气工程及其自动化 吗卖批*/ 
// 			printf(" %d ", i);	    
// 		putchar('\n');			    
// 	}
// }

