/*【例8-7】在以下程序中，主函数main调用了3个函数swap1、swap2和swap3，
还定义了变量a和b，
程序设计的目的是要求通过函数调用，
交换main中变量a和b的值。
请分析在swap1、swap2和swap3这3个函数中，
哪个函数可以实现这样的功能。
*/

/*  分别使用变量和指针作为函数参数的示例程序 */
# include <stdio.h>
int main (void)
{
    int a = 1, b = 2;
    int *pa = &a, *pb = &b;
    void swap1(int x, int y), swap2( int *px, int *py ), swap3 (int *px, int *py);
   
    swap1 (a, b);    				/* 使用变量a，b调用函数swap1() */
    printf ("After calling swap1: a=%d b=%d\n", a, b);

    a = 1; 
    b = 2;
    swap2(pa, pb);     			/* 使用指针pa，pb调用函数swap2()*/
    printf ("After calling swap2: a=%d b=%d\n", a, b);

    a = 1; 
    b = 2;
    swap3(pa, pb);     			/* 使用指针pa，pb调用swap3() */
    printf ("After calling swap3: a=%d b=%d\n", a, b);

    return 0;
}

void swap1 (int x, int y)
{
    int t;

    t= x; 
    x = y; 
    y = t;
}

void swap2 (int *px, int *py)
{
    int t;

    t = *px; //是修改指针指向的值
    *px = *py; 
    *py = t;
}

void swap3 (int *px, int *py)
{
    int *pt;

    pt =px;  //修改指针存放的地址
    px = py; 
    py = pt;
}
