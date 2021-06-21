#include <stdio.h>
#include <math.h>
 
int main() {
    // insert code here...
    // TODO Auto-generated method stub
    int a,b;
    int quotient=0;
     
    scanf("%d/%d",&a,&b);
    if (a<b&&a>0) {
        printf("0.");
    }
    for (int i=0; i<200; i++) {
        if(a*10>=b)
        {
            quotient=a*10/b;
            a=a*10%b;
            printf("%d",quotient);
        }
        else
        {
            a=a*10;
            printf("0");
        }
        if(a%b==0)
        {
             
            break;
             
        }
    }
    printf("\n");
 
}
