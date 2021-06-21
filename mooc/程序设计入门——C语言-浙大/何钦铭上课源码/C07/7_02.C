/*【例7-2】利用数组计算fibonacci数列的前10个数，
即1, 1, 2, 3, 5, ……，并按每行打印5个数的格式输出。*/
//都是需要时间  听 就多听 说就多说 读就多看 写 就多写。。从简到难  代码就是一行一行敲出来的

//敲代码也是一个思考的过程  先抄再写
/* 输出 fibonacci 数列 */
#include <stdio.h>
int main(void){

    int i ;
    int fib[999] = {1 , 1};
    for (i = 2; i < 99; ++i)
    {
        fib[i] = fib[i-1] +fib[i-2];
    }

    for(i = 0;i < 99; i++){
        printf("%6d",fib[i]);
        if ((i+1)%5 == 0)
        {
            printf("\n");
        }
    }
    return 0;
}


// #include <stdio.h>
// int main(void)
// {
//     int i;
//     int fib[20] = {1, 1};      	/* 数组初始化，生成fibonacci数列前2个数 */

//     /* 计算fibonacci数列剩余的8个数 */
//     for(i = 2; i < 10; i++)    
//         fib[i] = fib[i - 1] + fib[i - 2];

//     /* 输出fibonacci数列 */
//     for(i = 0; i < 10; i++){ 
//         printf("%6d", fib[i]);
//         if((i + 1) % 5 == 0)		/* 每输出5个数就换行 */
//             printf("\n");  
//      }

//     return 0;
// }

