/*【例5-8】写出下列程序的输出结果。*/
#include <stdio.h>
void fun(int k);
int main(void)
{
    int k;
    for(k =1; k<= 6; k++)
        fun(k);
    return 0;
}

void fun(int k)
{
    static int a;
    printf("%d, ",a);
    a +=k;
}




// #include <stdio.h>
// void fun(int k);
// int main(void)
// {
//     int k;
//     for (k = 1; k <= 6; k++) 
//         fun(k); 			/* 循环调用3次 */

//     return 0;
// } 
// void fun(int k)
// {
//     static int a;			/* 静态局部变量a的初值为0 */

//     printf("%d, ", a); 
//     a += k ;    			/* 静态变量a会记住前一次调用时留下来的值 */
// }

