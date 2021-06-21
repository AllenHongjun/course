#include <stdio.h>
int main(void)
{ 
    int n;
    double f;

    printf("Input n: ");  		
    scanf("%d", &n);
    f = fact(n);   /*调试时设置断点*/
    printf("%d!=%f\n", n, f);

    return 0;    /*调试时设置断点*/
}

double fact(int m)
{
    int i;
    double product;

    for ( i = 1; i <= m; i++ )  	
    	product = product * i;

    return product;    /*调试时设置断点*/
}
