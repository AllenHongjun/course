/*【例3-4】查询自动售货机中商品的价格。*/

/* 查询自动售货机中商品的价格 */
#include <stdio.h>
int main(void)
{
    int choice, i;
    double price;

    for( i = 1; i <= 5; i++) {     	    /*  for 的循环体语句开始 */  // 程序的限制  只能循环查找5次  如果明确的知道程序查找的次数 是可以用这个 for  现在的问题是 如果 程序比较的 长的话 就没有使用 函数的声明  和使用 不熟练  指针还没有学到 但是要相信要沉浸在写代码当中去  要沉浸当中  沉浸当中
        /* 以下5行显示菜单 */
        printf("[1] Select crisps \n");     /* 查询薯片价格 */
        printf("[2] Select popcorn \n");    /* 查询爆米花价格 */
        printf("[3] Select chocolate \n");  /* 查询巧克力价格 */
        printf("[4] Select cola \n");       /* 查询可乐价格 */
        printf("[0] exit \n");              /* 退出查询 */

        printf("Enter choice: ");      	    /* 输入提示 */
        scanf("%d", &choice);       	    /* 接受用户输入的编号 */

        /* 如果输入0，提前结束 for 循环 */
        if(choice == 0)           
            break;       		    /* 此处用 break 跳出 for 循环 */
        /* 根据输入的编号，将相应的价格赋给price */
        switch (choice) {         
           case 1: price=3.0; break;        /* 用break跳出switch语句，下同 */
           case 2: price=2.5; break;
           case 3: price=4.0; break;
           case 4: price=3.5; break;
           default: price=0.0; break;
        }
        /* 输出商品的价格 */
        printf("price = %0.1f\n", price);  
    }                                       /*  for 的循环体语句结束 */

    printf("Thanks \n");                    /*  结束查询，谢谢用户使用 */

    return 0;
}
