#include <stdio.h>
#include <stdlib.h>
int main(void)
{	
    char ch;
    FILE  fp;     
  	
    if((fp = fopen("a.txt", "w")) != NULL){ 
        printf("Con't Open File!");
	exit(0);
    }
    while((ch = getchar()) !='\n' )  /* 调试时设置断点 */
        fputc(ch, fp);
    fclose(fp);

    return 0;   
}  /* 调试时设置断点 */

