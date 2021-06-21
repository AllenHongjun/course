/*
【例8-13】输入n个整数存放在数组中，试通过函数调用的方法实现数组元素的逆序存放。
*/

/*  数组元素的逆序存放   这里其实一直都是在说数组是一个指针  数学 很英语主要都是辅助我学号计算机课程*/
#include <stdio.h>
int main(void)
{
    int i, a[10],n;
    void reverse(int p[ ], int n);	/*  申明函数 */
		
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    for(i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    reverse(a, n);  			/* 调用逆序函数 */
    for(i = 0; i < n; i++) 
        printf("%d\t", a[i]);

    return 0;
}
    
/* 使用数组作为函数参数实现逆序存放 */
void reverse(int p[], int n)
{
    int i, j, t;

    for(i=0, j=n-1; i<j; i++, j--) {	/*  交换数组元素位置  */
        t = p[i];
        p[i] = p[j];
        p[j] = t;
    }
}
