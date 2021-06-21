/*¡¾Àý10-6¡¿ºêµÄ×÷ÓÃ·¶Î§¡£*/

#include <stdio.h>
#define  A  "This is the first macro"
void  f1( )
{
    printf("A");
    printf("\n");
}
#define  B  "This is the second macro" 
void  f2( )
{
    printf(B); 
}
//#undef  B
int main(void)
{
   f1( );
   f2( );

   return 0;
}
