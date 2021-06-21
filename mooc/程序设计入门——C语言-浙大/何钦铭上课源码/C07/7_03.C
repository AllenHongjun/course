/*【例7-3】输入5个互异的整数，（就是不一样的正整数）
将它们存入数组a中，
再输入1个数x，然后在数组中查找x，如果找到，输出相应的下标
，否则，输出"Not Found"。*/

/* 在数组中查找一个给定的数 不同的编辑器环境 写代码的感觉是完全的不一样呀
要么就不要学 要学就要认真的学  认真的做
*/

#include <stdio.h>
int main(void){
  int a[5];
  int i,flag,x;
  printf("Enter 5 intergers: ");
  for(i = 0; i < 5 ; i++){
    scanf("%d", &a[i]);  //注意这里的数组前面也有一个&符号 用一个循环来个数组赋值 这样所有的值就一行输入 所有的值都保存在 数组中
  }

  printf("Enter x: ");
  scanf("%d",&x);

  flag = 0;
  for(i = 0; i < 5; i++){
    if (a[i] == x)
    {
      printf("Index is %d \n",i);
      flag = 1;
      break;
    }
  }

  if (flag == 0)
  {
    printf("Not Fount!");
  }

  return 0 ;
}



// #include <stdio.h>
// int main(void)
// {
//     int i, flag, x;
//     int a[5];    

//     printf("Enter 5 integers: ");	/* 提示输入5 个数 */
//     for(i = 0; i < 5; i++) 
//         scanf("%d", &a[i]);
//     printf("Enter x: ");        	/* 提示输入 x */
//     scanf("%d", &x);
//     /* 在数组a中查找x */
//     flag = 0;                	        /* 先假设x不在数组a中，置flag为0 */
//     for(i = 0; i < 5; i++) 
//         if(a[i] == x){        	        /* 如果在数组a中找到了x */
//             printf("Index is %d\n", i); /* 输出相应的下标 */
//             flag = 1;              	/* 置flag为1，说明在数组a中找到了x */
//             break;                 	/* 跳出循环 */
//         }
//     if(flag == 0)    			/* 如果flag为0，说明x不在a中 */
//         printf("Not Found\n");

//     return 0;
// }    


