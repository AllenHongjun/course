/* 【例4-8】输入一个正整数，将其逆序输出。例如，输入12345，输出54321。*/

/* 逆序输出一个正整数 */
#include <stdio.h>
int main(void)
{
    int x; 

    printf("Enter x: ");      /* 输入提示 */
    scanf ("%d", &x);
    while(x != 0){
        printf("%d ", x%10);
        x = x / 10;
    }

    return 0;
}

