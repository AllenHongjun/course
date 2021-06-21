/* 【例3-3】分段计算水费 */

/* 计算多分段函数 */
# include <stdio.h> 
int main(void)
{
   double x, y;           /* 定义2个双精度浮点型变量  编辑器 工具  你可以选择 一下  你觉的那个用的顺手 就用那个 */

   printf("Enter x:");    /* 输入提示 */
   scanf("%lf", &x);      /* 输入 double 型数据用 %lf */
   if (x < 0){
       y = 0;     	  /* 满足x＜0 */
   }
   else if (x <= 15){
       y = 4 * x / 3;      /* 不满足x＜0，但满足x≤15，即满足0≤x≤15 */
   }
   else{
      y = 2.5 * x - 10.5;  /* 既不满足x＜0，也不满足x≤15，即满足x>15 */
   }
   printf("f(%.2f) = %.2f\n", x, y); 

   return 0;
}


int test(void){
	double x,y;
	printf("Enter x: ");
	scanf("%lf", &x);
	if (x < 0)
	{
		y = 0;
	}
	else if (x <= 15)
	{
		y = 4 * x /3;
	}else{
		y = 2.5 * x -10.5;
	}
	

	/*  控制台程序  网页程序 安卓程序 苹果 程序 pc桌面程序  界面布局  美工 又有很多的分工  每一帧 每一个动画*/
	printf("f(%2.f) = %.2f \n",x,y);

	return 0;

}

