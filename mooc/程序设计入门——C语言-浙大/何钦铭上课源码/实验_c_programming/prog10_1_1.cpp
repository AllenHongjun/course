#include <stdio.h>							
int main(void)								
{
    extern int Add(int a, int b);				
    extern int Sub(int a, int b);				
    int x, y, z;								
    char ch;									

    scanf("%d%c%d", &x, &ch, &y);				
    if(ch=='+')								
	z=Add(x,y);							
    else if(ch=='-')								
	z=Sub(x,y);							
    else										
	printf("ÔËËã·ûÊäÈë´íÎó£¡\n");			
    printf("%d%c%d=%d\n", x, ch, y, z);			

    return 0;									
}										
