#include <stdio.h>
//#include <math.h>
 
int main() {
    // insert code here...
    // TODO Auto-generated method stub
    int max=0,maxn[2]={-1,-1};
    int n,c=1;
    int a[100][100]={0};
    scanf("%d",&n);
    int i,j; 
    for( i=0;i<n;i++)
    {
        for( j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
 
    for( i=0;i<n;i++)
    {
        max=0;
        for( j=0;j<n;j++)
        {
            if(max<a[i][j])
            {
                max=a[i][j];
                maxn[0]=i;
                maxn[1]=j;
            }
        }
 
        int g=1;
        for( j=0;j<n;j++)
        {
 			//这里的判断有点不理解呀 
            if (a[j][maxn[1]]<max&&i!=j)
            {
                g=0;
                break;
            }
 
        }
        if(g)
        {
            printf("%d %d\n",maxn[0],maxn[1]);
            c=0;
        }
 
        }
    if(c)
    {
        printf("NO\n");
    }
}
