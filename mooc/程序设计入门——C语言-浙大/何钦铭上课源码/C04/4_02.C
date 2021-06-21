/*【例4-2】从键盘输入一批学生的成绩，统计平均分。*/

/* 输入一批学生的成绩，以负数作为结束标志，统计平均分 */
#include <stdio.h>
int main(void)
{
    int num;               	/* 用 num 记录输入数据的个数，以便统计平均分 */
    double grade, total; 	/* grade 存放输入的成绩, total保存成绩之和 */

    num = 0;
    total = 0;
    printf("Enter grades: ");    	/* 输入提示 */
    scanf ("%lf", &grade);      	/* 输入第1个数据，%lf中的l是字母 */

    /* 当输入数据 mark 大于等于0时，执行循环 */
    while(grade >= 0){   
	total = total + grade;    	/* 累加成绩 */
	num++;    		        /* 计数 */
        scanf ("%lf", &grade);  	/* 读入一个新数据，为下次循环做准备 */
    }
    if(num != 0)
       printf("Grade average is %.2f\n", total/num);
    else
       printf("Grade average is 0\n");

    return 0;
}
