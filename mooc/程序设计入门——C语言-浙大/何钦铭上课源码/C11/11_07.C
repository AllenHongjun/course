/*
【例11-7】编写C程序echo，它的功能是将所有命令行参数在同一行上输出。
*/

/* 显示所有的命令行参数  */
#include <stdio.h> 
int main(int argc, char *argv[ ])
{   
    int k;
    for(k = 1; k < argc; k++)   	/* 从第1个命令行参数开始 */
        printf("%s ", argv[k]); 	/* 打印命令行参数 */
    printf("\n");

    return 0;
}
