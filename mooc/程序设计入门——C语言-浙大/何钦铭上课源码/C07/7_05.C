/*【例7-5】将1个3 * 2的矩阵存入1个3 * 2的二维数组中，找出最大值以及它的行下标和列下标，并输出该矩阵。*/

//写这种小程序的成就感要大好多呀。
/* 找出矩阵中的最大值及其行下标和列下标  比较底层的编程能力 */
#include <stdio.h>
int main(void)
{
  int col,row,i,j;
  int a[3][2];

  printf("Enter 6 integers: \n");
  for(i = 0; i < 3; i++)
    for(j = 0; j< 2; j++)
      scanf("%d",&a[i][j]);

  /*按二维矩阵的形式输出a*/
  for(i = 0; i < 3; i ++){
    for(j = 0; j < 2; j++){
          printf("%4d",a[i][j]);
    }
    printf("\n");
  }  
  row = col = 0;
  for(i = 0; i < 3; i++)
    for(j = 0;j < 2; j++)
      if(a[i][j] > a[row][col]){
        row = i;
        col = j;
      }
  printf("max = a[%d][%d] = %d\n",row,col,a[row][col]);
  return 0;    
}


// #include <stdio.h>
// int main(void)
// {
//     int col, i, j, row;
//     int a[3][2];

//     /* 将输入的数存入二维数组 */   
//     printf("Enter 6 integers: \n");     /* 提示输入6 个数 */
//     for(i = 0; i < 3; i++)
//         for(j = 0; j < 2; j++)       
//             scanf("%d", &a[i][j]); 

//     /* 按矩阵的形式输出二维数组a */
//     for(i = 0; i < 3; i++){
//         for(j = 0; j < 2; j++)
//             printf("%4d", a[i][j]); 
//         printf("\n");
//     }

//     /* 遍历二维数组，找出最大值 a[row][col] */
//     row = col = 0;                     /* 先假设 a[0][0] 是最大值 */
//     for(i = 0; i < 3; i++) 
//        for(j = 0; j < 2; j++)
//           if(a[i][j] > a[row][col]){   /* 如果 a[i][j] 比假设值大 */
//               row = i;                 /* 再假设 a[i][j] 是新的最大值 */
//               col = j; 
//           }
//     printf("max = a[%d][%d] = %d\n", row, col, a[row][col]);

//     return 0;
// }    
