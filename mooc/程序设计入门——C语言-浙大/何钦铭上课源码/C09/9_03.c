/* 程序名：例9-3.cpp  */

/* 功能：结构变量作为函数参数，计算职工的实发工资 */

#include <stdio.h>
struct employee
{
	int num;
	char name[20];
	float jbgz,jj,bx,sfgz;
};

//结构又不是至指针 为什么可以传入到函数中直接修改值  这里 是返回修改之后的值 不是 返回 修改值 之后的这个结构 这个是返回不了的
float count_sfgz(struct employee m);

int main(void)
{
	int i,n;
	struct employee e;
	
	printf("请输入职工人数n:");
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%s", &e.num, e.name);
        scanf("%f%f%f", &e.jbgz, &e.jj, &e.bx);
		e.sfgz = count_sfgz(e);
		printf("编号:%d 姓名:%s 实发工资:%.2f\n", e.num, e.name, e.sfgz);
	}
	return 0;
}

//结构变量 是值传递 结构的指针是 传递地址  相当于是应用传递。
float count_sfgz(struct employee m)
{
	return m.jbgz+m.jj-m.bx;
}












