#include <stdio.h>
void main( )
{
    char sign;
    int x,y; 

    printf("����x ����� y��");
    scanf("%d%c%d", &x, &sign, &y);
    if(sign='*')
        printf("%d * %d = %d\n",x,y,x*y);
    else if(sign='/')
	printf("%d / %d = %d\n",x,y,x/y);
    else if(sign='%')
	printf("%d Mod %d = %d\n",x,y,x%y);
    else
	printf("������������\n");		
}

