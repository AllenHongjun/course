#include <stdio.h>
int main(void)
{ 
    int n;
    double f;

    printf("Input n: ");  		
    scanf("%d", &n);
    f = fact(n);   /*����ʱ���öϵ�*/
    printf("%d!=%f\n", n, f);

    return 0;    /*����ʱ���öϵ�*/
}

double fact(int m)
{
    int i;
    double product;

    for ( i = 1; i <= m; i++ )  	
    	product = product * i;

    return product;    /*����ʱ���öϵ�*/
}
