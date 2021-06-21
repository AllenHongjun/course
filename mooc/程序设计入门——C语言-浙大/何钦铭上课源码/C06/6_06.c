/*【例6-6】逻辑表达式的运用。*/

/* 逻辑运算示例 */

#include <stdio.h>
int main(void){

    char ch = 'w';
    int a = 2,b = 0,c =0;  //先阶段C语言的乐趣就是就是这些基础的字符操作 他的乐趣在于非常的严谨
    
    float x = 3.0;

    printf("%d ",a && b); // 0
    printf("%d ",a || b && c); // 0  1/*exp1 || exp2先算exp1，若其值为1，STOP*/
    printf("%d ",!a && b);// 0
    printf("%d ",a||3 + 10&&2); //2   1
    printf("%d ",!(x == 2)); //1
    printf("%d ",!x == 2); //0
    printf("%d\n", ch || b);//1
    return 0;
}


// #include <stdio.h> 
// int main(void)
// {
//     char ch = 'w';
//     int a = 2, b = 0, c = 0;
//     float x = 3.0; 

//     printf("%d ", a && b);
//     printf("%d ", a || b && c);
//     printf("%d ", !a && b);
//     printf("%d ", a||3+10&&2);
//     printf("%d ", !(x == 2));
//     printf("%d ", !x == 2);
//     printf("%d\n ", ch || b);

//     return 0;
// }
