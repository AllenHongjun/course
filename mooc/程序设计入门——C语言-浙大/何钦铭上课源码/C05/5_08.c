/*����5-8��д�����г������������*/
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
//         fun(k); 			/* ѭ������3�� */

//     return 0;
// } 
// void fun(int k)
// {
//     static int a;			/* ��̬�ֲ�����a�ĳ�ֵΪ0 */

//     printf("%d, ", a); 
//     a += k ;    			/* ��̬����a���סǰһ�ε���ʱ��������ֵ */
// }

