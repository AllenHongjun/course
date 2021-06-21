/*【例7-4】输入一个正整数n (1＜n≤10)，再输入n个整数，将它们存入数组a中。
(1) 输出最小值和它所对应的下标。
(2) 将最小值与第1个数交换，输出交换后的n个数。
*/

/* (2) 将最小值与第1个数交换，输出交换后的n个数。 */

#include <stdio.h>
void main()
{
    int i,index,n,temp;
    int a[10];
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    for(i = 0; i< n; i++){
        scanf("%d", &a[i]);
    }

    //找出最小值
    index = 0;
    for(i = 1; i < n; i++){
        if(a[i] < a[index])
            index = i;
    }

    temp = a[index];
    a[index] = a[0];
    a[0] = temp;
    for(i = 0; i < n; i++)
        printf("%d   ",a[i]);
}


// #include <stdio.h>
// void main( )
// {
//     int i, index, n, temp;
//     int a[10];    

//     printf("Enter n: ");            	/* 提示输入n */
//     scanf("%d", &n);
//     printf("Enter %d integers: ", n); 	/* 提示输入n 个数 */
//     for(i = 0; i < n; i++)  
//         scanf("%d", &a[i]);

//     /* 找最小值a[index] */
//     index = 0;           	         假设a[0]是最小值，即下标为0的元素最小 
//     for(i = 1; i < n; i++)  
//         if(a[i] < a[index]) 	        /* 如果 a[i] 比假设的最小值还小 */
//             index = i;                  /* 再假设 a[i] 是新的最小值，即下标为 i 的元素最小 */

//     temp = a[index];    /* 以下3句交换最小值 a[index] 和第1个数 a[0] */
//     a[index] = a[0];
//     a[0] = temp;

//     for(i = 0; i < n; i++) 
//         printf("%d ", a[i]);
// }    

