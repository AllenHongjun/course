/* 【例3-8】输入1个整数，输出它的绝对值。*/

/* 求绝对值 */
#include <stdio.h> 
int main(void)
{
    int number;       		

    printf("Enter a number: ");     	/* 输入提示 */
    scanf("%d", &number);
    if(number < 0)  
       number = -number; 	/* 如果number小于0，计算其相反数 */
    printf("The absolute value is %d.\n", number);

    //工欲善其事 必先利其器 vs 如何来编译和运行C语言。。这个代码都有了。就是需要自己去调试和测试。
    return 0;
}
