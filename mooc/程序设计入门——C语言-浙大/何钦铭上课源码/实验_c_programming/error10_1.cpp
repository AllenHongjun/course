#include <stdio.h>
int main(void)
{

    int n;
    double x, root; 

    printf("Enter x:");
    scanf("%lf, &x);
    printf("Enter n:");
    scanf("%d", &n);
    root = fun(n, x);
    printf("Root = %0.2f\n", root);

     return 0;
}  
double fun(int n, double x)
{
    if(n == 1)		
	return 1;		
    else 
	return x * fun(n-1, x);
}
