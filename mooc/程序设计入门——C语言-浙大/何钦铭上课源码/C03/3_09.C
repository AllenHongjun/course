/* 【例3-9】输入一个正整数n，再输入n个学生的成绩，计算平均分，并统计不及格成绩的个数。*/

#include <stdio.h>
int main(void)
{
    int count, i, n;                     /* count 记录不及格成绩的个数 */
    double grade, total;                 /* grade 存放输入的成绩, total保存成绩之和 */

    printf("Enter n: ");                 /* 提示输入成绩个数n   这里的i是一个计数器的作用*/
    scanf("%d", &n);
    total = 0;
    count = 0;
    for(i = 1; i <= n; i++){
        printf("Enter grade #%d: ", i);  /* 提示输入第i个成绩  有一些学习的经历  知道如何学习  学会学习。*/
		scanf ("%lf", &grade);      	 /* 输入第i个成绩 */
		total = total + grade;    	 /* 累加成绩 */
		if(grade < 60)    	         /* 统计不及格成绩的个数 */
            count++;
    }
    printf("Grade average = %.2f\n", total/n);
    printf("Number of failures = %d\n", count);

    return 0;
}

test (void){
	int count ,i ,n;
	double grade,total;

	printf("Enter n : ");
	scanf("%d", &n);
	total  = 0;
	count = 0;
	for( i  = 1; i <= n; i++){
		printf("Enter grade #%d:",i);
	}

	scanf("%lf",&grade);
	total = total + grade;

	if (grade < 60)
	{
		count ++;
	}

	printf("Grade average = %.2f\n",total /n);
	printf("Number of failures = %d\n",count);

	return 0;


}