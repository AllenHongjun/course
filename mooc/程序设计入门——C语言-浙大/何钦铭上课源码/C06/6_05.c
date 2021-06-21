/*【例6-5】关系表达式的运用。*/

/*  关系运算示例 */

#include <stdio.h>
int main(void){

	char ch ='w';
	int a =2, b = 3,c =1 ,d,x =10;
	printf("%d ",a > b == c);  //主要是设计运算符的优先级  逻辑运算的魅力
	printf("%d ",d = a > b);
	printf("%d ",ch > 'a' + 1);


	printf("%d ",d = a +b >c); 
	printf("%d ",b -1 == a !=c);  //这个样子太拗口 我觉得还是加上（）比较方便
	//printf("%d \n",3 <= x <=5);
}


// #include <stdio.h> 
// int main(void)
// {
//     char ch = 'w';
//     int a = 2, b = 3, c = 1, d, x=10;

//     printf("%d ", a > b == c);
//     printf("%d ", d = a > b);
//     printf("%d ", ch >'a' + 1);
//     printf("%d ", d = a + b > c);
//     printf("%d ", b - 1 == a != c);
//     printf("%d\n", 3 <= x <= 5);

//     return 0;
// }
