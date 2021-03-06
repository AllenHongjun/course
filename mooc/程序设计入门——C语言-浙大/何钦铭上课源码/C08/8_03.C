/*【例8-3】通过使用指针操作改变所指变量的值的程序示例。*/

/*  通过指针操作改变变量的值 事情如果拖到很紧急的时候才做的话 就变得很难了。*/
// 安装一个一个编译器 然后编译运行。其实就两步 没有那么麻烦
// 取出改指针所指向的哪个变量的值。 
# include <stdio.h>
int main (void)
{
    int a = 1, b = 2, t;
    int *p1, *p2;
   	
    p1 = &a; p2 = &b;       	  /* 关联指针和变量，使p1指向a，p2指向b */
    printf ("a=%d, b=%d, *p1=%d, *p2=%d\n", a, b, *p1, *p2);
   
    t = *p1; *p1 = *p2; * p2 = t; /* 交换*p1和*p2的值 */
    printf ("a=%d, b=%d, *p1=%d, *p2=%d\n", a, b, *p1, *p2);

    return 0;
}
