/*����5-7��ȫ�ֱ������塣*/

#include "stdio.h"
int x;					/* ����ȫ�ֱ���x */
int f( )
{ 
    int x = 4;			/* xΪ�ֲ��������ڱ������У�ȫ�ֱ���x�������� */

    return x;
}
int main(void)
{
    int a = 1;  

    x = a;   			/* ��ȫ�ֱ��� x ��ֵ1 */
    a = f( );  			/* a��ֵΪ4 */
    {
        int b = 2; 
    	b = a + b;		/* b��ֵΪ4 */
    	x = x + b;		/* ȫ�ֱ������� a=4  x=7*/ 
    }
    printf("%d %d" , a, x );

    return 0;
}


