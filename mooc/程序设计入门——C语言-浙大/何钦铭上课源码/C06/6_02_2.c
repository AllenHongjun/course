/*【例6-2】使用基本格式控制说明%d、%o和%x输入输出整型数据。*/

/* 用 %o 输入整型数据示例 */

#include <stdio.h>
int main(void)
{

	int a,b;
	printf("input a,b: ");
	scanf("%o%d",&a,&b);  //格式化输入字符串  会要求输入两个数字   
	printf("%d %5d\n",a,b);  //统筹能力可以  需要的是一种执行力  中间的空格会输出 %5d 表示会用5个字符的长度来输出
}




// #include <stdio.h>    
// int main(void)
// {   
//     int a, b;    

//     printf("input a, b: ");
//     scanf("%o%d", &a, &b); 
//     printf("%d %5d\n", a, b);   //%5d指定变量b的输出宽度为5 

//     return 0;
// }


// int test(void)
// {
// 	int a, b;
// 	printf("input a, b: \n");
// 	scanf("%o%d",&a ,&b); 
// 	printf("%d %5d\n", a,b);

// 	return 0 ;
// }
