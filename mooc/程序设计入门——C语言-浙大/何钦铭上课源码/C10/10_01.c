/*【例10-1】设计一个常用圆形体体积的计算器，采用命令方式输入1、2、3，分别选择计算球体、圆柱体、圆锥体的体积，并输入计算所需的相应参数。*/

/*  常用圆形体的体积计算器，1：计算球体，2：计算圆柱，3：计算圆锥 */
#include <stdio.h>
#include <math.h>
#define  PI  3.141592654
void cal ( int sel );     /*  函数声明  */
int main(void)
{
    int sel; 

/*  循环选择计算圆形体的体积，直到输入非1～3的数字为止  */
    while(1){			/* 永久循环，通过循环体中 break 语句结束循环 */
		printf("  1-计算球体体积\n");		
		printf("  2-计算圆柱体积\n");
		printf("  3-计算圆锥体积\n");
		printf("  其他-退出程序运行\n");
		printf("请输入计算命令：");  	/* 输入提示*/
		scanf("%d", &sel);
		if (sel < 1|| sel > 3)			/* 输入非1～3的数字，循环结束  */
            break;     	
		else							/* 输入1～3，调用cal()  */
            cal (sel);
	 }

	 return 0;
}
//一段时间 我只适合学习一门课程或者两门课程。。学完一门是一门。。不要太看重mooc的证书 我一端一天 或者几天时间只适合做一件事情 不适合多任务切换
/*  常用圆形体体积计算器的主控函数  */
void cal ( int sel )
{
	double  vol_ball(void);				/*  函数声明  */
	double  vol_cylind(void);
	double  vol_cone(void );
	switch (sel) {
    	case 1: 		/*  计算球体积  */
			printf("球体积为：%.2f\n",vol_ball());
			break;
        case 2:  		/*  计算圆柱体积  */
			printf("圆柱体积为：%.2f\n",vol_cylind( ));
			break;
        case 3:  		/*  计算圆锥体积  */
			printf("圆锥体积为：%.2f\n",vol_cone( ));
			break;
	}
}

/* 计算球体体积 V=4/3*PI*r*r*r  */
double vol_ball( )
{
	double r;

	printf("请输入球的半径：");
	scanf("%lf", &r);
	return(4.0/3.0*PI*r*r*r);
}
/*  计算圆柱体积 V=PI*r*r*h  */
double vol_cylind( )
{
	double r , h;

	printf("请输入圆柱的底圆半径和高：");
	scanf("%lf%lf", &r, &h);
	return(PI*r*r*h);
}

/*  计算圆锥体积 V=h/3*PI*r*r  */
double vol_cone( )
{
	double r , h;

	printf("请输入圆锥的底圆半径和高：");
	scanf("%lf%lf", &r,&h);
	return(PI*r*r*h/3.0);
}
