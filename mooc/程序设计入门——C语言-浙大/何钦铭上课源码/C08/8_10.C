/*
【例8-10】使用指针计算数组元素个数和数组元素的存储单元数。
*/

/*  指针和数组及存储单元  */
# include <stdio.h>
int main (void)
{
    double a[2], *p, *q;

    p = &a[0];               		/* 指针p向数组a的首地址 */
    q = p + 1;               		/* 指针q指向数组元素a[1] */
    printf ("%d\n", q - p);      	/* 计算指针p和q之间的元素的个数 */

    printf("%x\n",q);
    printf("%p\n",q);   //计算机中地址是怎么用16进制表示的？
   // printf ("%d\n", (int) q - (int) p); /* 计算指针p和q之间的字节数  这里爆出了一个异常 暂时还无法处理 */

    return 0;
}
