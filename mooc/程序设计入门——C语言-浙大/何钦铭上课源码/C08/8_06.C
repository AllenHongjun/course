/*【例8-6】调用以指针作为参数的函数来模拟狸猫换太子的故事*/

/*  使用指针作为函数参数的示例程序 */
#include <stdio.h>
#define CIVET 0        /* 定义狸猫值为0 */
#define PRINCE 1       /* 定义王子值为1 */
void replace1(int baby);
void replace2(int *baby);
void display(int who);

int main(void)
{
    int baby;		/*变量baby代表出生的孩子 */
    baby = PRINCE;      /* 刚出生时是王子 */ 	

    printf("before change, baby is ");	/* 输出交换前的信息 */
    display(baby);
	  
    replace1(baby);   /* 调用函数replace1，实施狸猫换太子第一次行动*/
 
    printf("\n");
    printf("after first action, baby is ");    /* 输出第一次行动后的信息 */
    display(baby);

    replace2(&baby);	/* 调用函数replace2，实施狸猫换太子第二次行动*/

    printf("\n");
    printf("after second action, baby is ");    /* 输出第二次行动后的信息 */
    display(baby);
		
    return 0;
}

void replace1(int baby)
{
    baby = CIVET;
}

void replace2(int *baby)
{
    *baby = CIVET;
}

void display(int who)
{
    if (who==CIVET)
	printf("狸猫");
    else if (who==PRINCE)
	printf("王子");
}
