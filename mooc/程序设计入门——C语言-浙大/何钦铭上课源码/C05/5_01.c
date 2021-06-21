/*【例5-1】输入圆柱的高和半径，求圆柱体积，volume=3.1415926*r*r*h。要求定义和调用函数cylinder (r, h )计算圆柱体的体积。 */


//先复习 理论的知识是有一些了但是 真正写代码 敲击代码的能力 才刚刚开始  要多敲 多敲 多敲
//practice  practice  practice  !!!

#include <stdio.h>
int main(void)
{
	double height,radius,volume;
	double cylinder(double r,double h);  //函数的原型

	printf("Enter radius and height: ");
	scanf("%lf%lf",&radius,&height);
	volume = cylinder(radius,height);
	printf("Volume = %.3f\n",volume);//保留3位小数  %.3f 小数点前面没有数字是上面意思？  
	return 0;
}

//函数的定义
double cylinder(double r,double h)
{
	double result;
	result = 3.1415926 * r * r * h;
	return result;
}





