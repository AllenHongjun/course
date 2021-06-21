/*【例10-4】写出下列递归程序的输出结果。*/

#include <stdio.h>
long fib(int g)
{
    switch(g){
        case 0: return 0;
        case 1:
        case 2: return 2;
    }
    printf("g=%d,", g);

    return fib(g-1) + fib(g-2);
}
int main(void)
{
    long k;

    k = fib(4);
    printf("k=%ld\n", k);

    return 0;
}
