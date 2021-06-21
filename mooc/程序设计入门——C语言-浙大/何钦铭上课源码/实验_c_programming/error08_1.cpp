#include <stdio.h>
void mov(int *, int, int);
int main()
{
    int m, n, i, a[80], *p;
    
    printf("Input n, m:");
    scanf("%d%d",&n,&m);
    for(p=a,i=0;i<n;i++)
        scanf("%d",&p++);
    mov(a,n,m);
    printf("After move: ");
    for(i=0;i<n;i++)
        printf("%5d",a[i]);

    return 0;
}
void mov(int *x, int n, int m)
{
    int i,j;

    for(i=0;i<m;i++){
        for(j=n-1;j>0;j--)
	    x[j]=x[j-1]; 		/* 调试时设置断点 */
	    x[0]=x[n-1]; 
    }
}
