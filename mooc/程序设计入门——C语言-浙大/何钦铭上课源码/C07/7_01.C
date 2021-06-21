/*【例7-1】输入一个正整数n (1<n≤10)，再输入n个整数，用选择法将它们从小到大排序后输出。*/

/* 选择法排序 */
#include <stdio.h>
int main(void)
{
    int i, index, k, n, temp;
    int a[10];         	/* 定义1个数组a，它有10个整型元素*/

    printf("Enter n: ");            	/* 提示输入n */
    scanf("%d", &n);
    printf("Enter %d integers: ", n); 	/* 提示输入n 个数 */
    /* 将输入数依次赋给数组a的n个元素a[0]～a[n-1] */   
    for(i = 0; i < n; i++)  
        scanf("%d", &a[i]);
    // 有几个数字 需要比较n次 很多时候都是用最笨的方法来实现。 每一次都找到里面最小的数字。。然后
    // 继续循环。 
    /* 对n个数排序    这个选择排序 具体每一步是如何实现的 ，选择排序的算法 不急 不慌 不纠结 。知道内容觉得上面才是最重要的  把握最重要的东西就可以了*/
    for(k = 0; k < n-1; k++){
        index = k;
        for(i = k + 1; i < n; i++)  
            if(a[i] < a[index])  index = i;    
        temp = a[index];
        a[index] = a[k];
        a[k] = temp;
    }

    printf("After sorted: ", n);
    /* 输出n个数组元素的值 */
    for(i = 0; i < n; i++)       
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}    
