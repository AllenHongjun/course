#include <stdio.h>  
main()  
{  
    int i,n,max = 0,Max = 0,t;  
    scanf("%d",&n);  
    for(i = 0;i<n;i++){  
        scanf("%d",&t);  
        max += t;  
        if(max>Max)  
            Max = max;  
        if(max<0)  
            max = 0;      
    }   
    printf("%d",Max);  
}  
