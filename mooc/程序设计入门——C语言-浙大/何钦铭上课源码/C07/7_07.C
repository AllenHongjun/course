 /*【例7-7】输入一个正整数n (1＜n≤6)，根据下式生成1个n*n的方阵，
 将该方阵转置（行列互换）后输出。
    a[i][j] = i * n + j + 1（0≤i≤n-1，0≤j≤n-1）
*/
#include <stdio.h>
int main(void){
    int i,j,n,temp;
    int a[6][6];
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 0; i < n;i++)
        for(j = 0; j< n;j++)
            a[i][j] = i * n + j + 1 ;
    for(i = 0; i < n; i++)
        for(j = 0;j < n; j++)
            if( i <=j){
                temp = a[i][j];
                a[i][j] = a[j][i];   //这个矩阵交换 每个值是怎么来的  线性代数 离散数学需要用到
                a[j][i] = temp;
            }

    for(i = 0; i < n; i++){
        for(j = 0;j < n;j ++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
    return 0;
}


// /* 方阵转置 */
// #include <stdio.h>
// int main(void)
// {
//     int i, j, n, temp;
//     int a[6][6];

//     /* 给二维数组赋值 */
//     printf("Enter n: ");
//     scanf("%d", &n);
//     for(i = 0; i < n; i++)              /* 行下标是外循环的循环变量 */        
//         for(j = 0; j < n; j++)    	/* 列下标是内循环的循环变量 */       
//             a[i][j] = i * n + j + 1; 	/* 给数组元素赋值 */
        
//     /* 行列互换*/
//     for(i = 0; i < n; i++)
//         for(j = 0; j < n; j++)
//             if(i <= j){         	/* 只遍历上三角阵 */
//                 temp = a[i][j]; 	/* 以下3句交换 a[i][j] 和 a[j][i] */
//                 a[i][j] = a[j][i];
//                 a[j][i] = temp;
//             }

//     /* 按矩阵的形式输出a */
//     for(i = 0; i < n; i++){     	/* 针对所有行的循环 */
//         for(j = 0; j < n; j++)   	/* 输出第i行的所有元素 */      
//             printf("%4d", a[i][j]); 
//         printf("\n");      		/* 换行 */         
//     }

//     return 0;
// }    
