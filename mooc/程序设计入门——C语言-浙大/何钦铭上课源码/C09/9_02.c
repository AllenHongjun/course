/* 程序名：例9-2.cpp  */

/* 功能：计算职工的实发工资 */

/*
#include<stdio.h>
struct employee{         
    int num;
    char name[20];
    float jbgz, jj, bx, sfgz;
};

int main(void)
{    
    int i, n;
    struct employee e;   

    printf("请输入职工人数n: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        printf("请输入第%d个职工的信息: ", i);
        scanf("%d%s", &e.num, e.name);
        scanf("%f%f%f", &e.jbgz, &e.jj, &e.bx);
        e.sfgz = e.jbgz + e.jj - e.bx;
        printf("编号:%d 姓名:%s实发工资:%.2f\n", e.num, e.name, e.sfgz);
    }

    return 0;
}
*/

#include <stdio.h>
struct employee
{        /*定义结构类型 emploayee*/
	int num;
	char name[20];
	float jbgz, jj, bx ,sfgz;

};

int main(void)
{
	int i,  n;
	struct employee e;  //定义结构类型变量 e
	
	printf("请输入职工人数n: ");
	scanf("%d",&n);
	for (i = 1; i <= n; i++)
	{
		printf("请输入第%d个职工的信息： ",i);
		scanf("%d%s", &e.num, e.name);
		scanf("%f%f%f", &e.jbgz, &e.jj, &e.bx);
		e.sfgz =  e.jbgz + e.jj - e.bx;
		printf("编号：%d 姓名：%s 实发工资 :%.2f\n", e.num, e.name, e.sfgz);
	}
	return 0;
}
