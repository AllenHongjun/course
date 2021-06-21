/*【例5-4】 输入精度e，使用格里高利公式求π的近似值，精确到最后一项的绝对值小于e。要求定义和调用函数funpi(e)求π的近似值。*/
                
/*  用格里高利公式计算π的近似值，精度为e  π/4=1-1/3+1/5-1/7+*/

#include <stdio.h>
#include <math.h>
int main(void){
	double e,pi;
	double funpi(double e);

	printf("Enter e:");
	scanf("%lf", &e);
	pi = funpi(e);
	printf("pi = %.4f\n",pi);
	return 0;
}

double funpi(double e)
{
	int denominator ,flag;
	double item,sum;

	flag = 1;
	denominator = 1;
	item = 1.0;
	sum = 0;

	while(fabs(item) >= e){
		item = flag * 1.0 /denominator;
		sum = sum +item;
		flag = -flag;
		denominator = denominator +2;
	}
	return sum * 4;
}

// double funpi(double e)					/* 定义计算pi的函数 */
// {
// 		int denominator, flag; 
// 		double item, sum;

// 		flag = 1;       				/* flag 表示第 i 项的符号，初始为正 */
// 		denominator = 1;				/* denominator表示第 i 项的分母，初始为1 */
// 		item = 1.0;        				/* item 中存放第 i 项的值，初值取 1 */
// 		sum = 0;            			/* 置累加和 pi 的初值为0 */

//     /*  当|item| ≥ e时，执行循环 */
// 		while(fabs(item) >= e){   
// 			item = flag * 1.0 / denominator;    	/* 计算第 i 项的值 */
// 			sum = sum + item;        				/* 累加第 i 项的值 */
// 			flag = -flag;   	 					/* 改变符号，为下一次循环做准备 */
// 			denominator = denominator + 2;			/* 分母递增2 ，为下一次循环做准备 */
// 		}
// 		return sum * 4;
// }


// #include <stdio.h>
// #include <math.h>
// int main(void)
// {
// 	   double e, pi;     				/* e 代表精度   这里的每一句话都有解释  而且可以调试 代码编写也规范 真的是严谨*/
// 	   double funpi(double e);			 函数声明 

//     	printf("Enter e:");				/* 提示用户输入精度 */
// 	   	scanf("%lf", &e);
// 	   	pi = funpi(e);					/* 调用函数，把返回值赋值给pi */
// 		printf ("pi = %.4f\n", pi);
// 		return 0;
// }
// double funpi(double e)					/* 定义计算pi的函数 */
// {
// 		int denominator, flag; 
// 		double item, sum;

// 		flag = 1;       				/* flag 表示第 i 项的符号，初始为正 */
// 		denominator = 1;				/* denominator表示第 i 项的分母，初始为1 */
// 		item = 1.0;        				/* item 中存放第 i 项的值，初值取 1 */
// 		sum = 0;            			/* 置累加和 pi 的初值为0 */

//     /*  当|item| ≥ e时，执行循环 */
// 		while(fabs(item) >= e){   
// 			item = flag * 1.0 / denominator;    	/* 计算第 i 项的值 */
// 			sum = sum + item;        				/* 累加第 i 项的值 */
// 			flag = -flag;   	 					/* 改变符号，为下一次循环做准备 */
// 			denominator = denominator + 2;			/* 分母递增2 ，为下一次循环做准备 */
// 		}
// 		return sum * 4;
// }

