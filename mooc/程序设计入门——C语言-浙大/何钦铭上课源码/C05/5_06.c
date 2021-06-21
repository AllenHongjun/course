/*【例5-6】在复合语句中定义局部变量。*/


#include <stdio.h>
int main(void){
	int a;
	a =1;
	{
		int b =2;
		b = a+b;
		a =a+b;
	}
	printf("%d ",a);
}



// #include <stdio.h>
// int main(void)
// {  
//     int a;

//     a = 1;
//     {					/* 复合语句开始 */
//         int b = 2;		 局部变量b的作用范围被局限于该复合语句内 
//         b = a + b;      
//         a = a + b;
// 	}					/* 复合语句结束 */
// 	printf("%d " , a );

// 	return 0;
// }
