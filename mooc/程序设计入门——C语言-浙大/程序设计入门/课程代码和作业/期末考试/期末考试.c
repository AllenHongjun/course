#include <stdio.h>
#include <string.h>
void swap( int *pa, int *pb ) 
{
    int pt;
    pt = *pa, *pa = *pb, *pb = *pa;
}
int main(void)
{    
	/*
   int number, right_digit;
	number = 15292;
	if ( number ==0 ) {
	    printf("0");
	} else
	    while  ( number != 0 ) {
	        right_digit = number % 10;
	        printf("%i", right_digit);
	        number /= 10;
    }
    */
    /*
    char s[]="Zhejiang";
	s[strlen(s)/2-1]=0;
	printf("%lu#%s#",strlen(s),s);
	*/
	
	/*
	int a = 6, b = 0, c = 3;
	int d;
	d = (a && b || b - c);
	
	printf("%d",d);*/
    
    /*
    int a[3][6];
    
    printf("%d",sizeof(int));
    printf("%d",sizeof(a[0]));
    */
    /*
    int x = 2;
    int c = (-10<x<0);
    
    printf("%d",c);
    */
    /*
    double a = (double)(10/4*4);
    printf("%f",a); 
    */
    /*
    int a = 0;
    if (4/5 > 3/4) 
    a=1; 
else 
    a=0;
    
    printf("%d",a);
    
    */
    int i ,j;
   for( i=0,j=10; i=j=10; i++,j--){
   	
   	printf("%d",i);
   }
   
    
}
