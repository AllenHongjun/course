/* 程序名：例9-4.cpp  */

/* 功能：按成绩从高到低输出学生信息 */
#include <stdio.h>
struct student{
    int  num;
    char name[20];//字符数组 char不是只能存放一个字符的吗？？ C语言的字符数组 用来存放字符串的。。默认的后面会有一个/0
    int  score;
}; 
struct student stud[10];	/* 定义记录10个学生信息的结构数组 */

int main(void)
{
    int i, j, index, sum = 0;
    struct student temp;	/* 工作变量 */

    /* 输入10个学生的记录，并累加成绩 */
    printf("\nInput the student's number, name and score: \n");
    for(i = 0; i < 10; i++){			
        printf("No %d: ", i+1);		/* 提示输入第i个同学的信息  */
        scanf("%d%s%d", &stud[i].num, stud[i].name, &stud[i].score);
        sum = sum + stud[i].score;
    }
    /* 按照分数从低到高排序，使用选择排序法 */
    for( i = 0; i < 9; ++i ){		/*  外部循环  */
        index =i;
        for (j = i+1; j <10; j++ )	/*  内部循环  */
            if (stud[j].score < stud[index].score)   /* 比较成绩的大小 */
                index = j;
        temp = stud[index];		/* 交换数组元素 */
        stud[index] = stud[i];
        stud[i] = temp;
    }
    /*  输出成绩 */
    printf("The average: %d\n", sum/10 );/* 输出平均分 */
    printf("The student score:\n"); 
    for (i = 9; i >= 0; i-- ) 
        printf("%d %s %d\n", stud[i].num, stud[i].name, stud[i].score);

    return 0;
}
