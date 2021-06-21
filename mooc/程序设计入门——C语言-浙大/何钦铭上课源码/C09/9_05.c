/* 程序名：例9-5.cpp */

/* 功能：设置学生成绩等级并统计不及格人数（结构指针作为函数参数） */
#include<stdio.h>
#define N 10
struct student{
    int num;
    char name[20]; //C语言用  字符数组的形式来保存字符串
    int score;
    char grade;
};
int set_grade(struct student *p);

int main(void)
{
    struct student stu[N], *ptr;
    int i, count;

    ptr = stu;
    printf("Input the student's number, name and score: \n");
    for(i = 0; i < N; i++){
       printf("No %d: ", i+1);		/* 提示输入第i个同学的信息  */
       scanf("%d%s%d", &stu[i].num, stu[i].name, &stu[i].score);
    } 
   count = set_grade(ptr);
   printf("The count (<60): %d\n", count);
   printf("The student grade:\n"); 
   for(i = 0; i < N; i++)
        printf("%d %s %c\n", stu[i].num, stu[i].name, stu[i].grade);
 
    return 0;
}


//总感觉 好像 看的懂 但是还写不出来。
int set_grade(struct student *p)
{
    int i, n = 0;
    for(i = 0; i < N; i++, p++){
        if(p->score >= 85)
            p->grade = 'A';
        else if(p->score >= 70)
            p->grade = 'B';
        else if(p->score >= 60)
            p->grade = 'C';
        else{ 
            p->grade = 'D';
            n++;
        }
    }

    return n;
}

/*
#include <stdio.h>
#define N 10
struct student
{
	int num;
	char name[20];
	int score;
	char grade;
};

int set_grade(struct student *p);

int main(void)
{
	struct student stu[N] , *ptr;
	
	int i ,count;

	ptr = stu;
	printf("Input the student's number, name and score:\n");

	for (i = 0; i< N ;i++ )
	{
		printf("No %d: ", i+1);
		scanf("%d%s%d",&stu[i].num, std[i].name,&stu[i].score);
	}
	count = set_grade(ptr);
	printf("The count (<60): %d \n",count);
	printf("The student grade: \n");

	for (i = 0 ;i < N ; i++)
	{
		printf("%d %s %c\c",stu[i].num, std[i].name, stu[i],grade);
	}
	return 0;

}

int set_grade(struct student *p)
{
	int i ,n = 0;
	for (i = 0; i< N ;i++,p++ )
	{
		if (p->score >=85)
		{
			p->grade = 'A';
		}else if(p->score >=70)
		{
			p->grade = 'B';
		}else if(p->score >= 60)
		{
			p->grade = 'C';
		}else{
			p->grade = 'D';
			n++
		}
	}

	return n;
}

*/






