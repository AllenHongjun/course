/*【例10-2】假定我们把例10-1的5个函数分别存储在2个.C文件上，要求通过文件包含把它们联结起来。*/

/*  常用圆形体的体积计算器，1：计算球体，2：计算圆柱，3：计算圆锥 */
#include <stdio.h>
#include <math.h>
#define  PI  3.141592654
void cal ( int sel );     /*  函数声明  */
#include  "prog2.c"
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