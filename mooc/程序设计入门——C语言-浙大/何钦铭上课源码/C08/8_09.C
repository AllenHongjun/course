/*
【例8-9】输入n个正整数，将它们从小到大排序后输出。要求使用冒泡排序算法。
*/


//先语言  再离散数学  ——————》数据结构 和一般的算法  高等数学  --》算法设计 算法导论--》 --盖一个小别墅软件工程 
/*  指针和数组及存储单元 - 冒泡排序算法 */
#include <stdio.h>
void swap2 (int *, int *);
void bubble (int a[], int n);
int main(void)
{    
    int n, a[8];
    int i;

    printf("Enter n (n<=8): ");
    scanf("%d", &n);
    printf("Enter a[%d] : ",n);
    for (i=0; i<n;i++)
        scanf("%d",&a[i]);
    bubble(a,n);

    printf("After sorted, a[%d] = ", n);
    for (i=0; i<n; i++)
        printf("%3d",a[i]);

    return 0;
}

void bubble (int a[], int n)  		/*  n是数组a中待排序元素的数量 */
{
    int  i, j;

    for( i = 1; i < n; i++)		/*  外部循环 先选取要比较的每一数字   */
        for (j = 0; j < n-i; j++ )	/*  内部循环  那每一数字 和后面的所有数字做比较  要自己感悟*/
            if (a[j] > a[j+1])		/*  比较两个元素的大小  */
                swap2 (&a[j], &a[j+1]);	/*  如果后一个元素大，则交换 */
}

void swap2 (int *px, int *py)
{
    int t;

    t = *px; 
    *px = *py; 
    *py = t;
}
