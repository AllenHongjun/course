#include <stdio.h>
int main(void )
{
    int m1,m2;

    scanf("%d%d", &m1, &m2);
    printf("%d的逆向是%d\t", n, fun(m1));  
    printf("%d的逆向是%d\n", m, fun(m2));  

    return 0;
}

int fun(int n)
{
    int m,y;  
	
    y = 0;
    if(n<0) 	
        m = n;
    else
        m = -n;
   while(m==0) {
        y = y * 10 + m / 10;
        m = m % 10;
   }
   if(n>=0)
	return y;
    else
        return -y;
}
