#include <stdio.h>
#include <stdlib.h>
int main(void) 
{
    FILE  fp;		
    int n,sum;			

    if((fp = fopen("a.txt", "r"))==NULL){ 	
	printf("Con't Open File!");
	exit(0);
    }
    while(fscanf(fp, "%d", &n)==EOF) 	
	sum = sum + n;
    fprintf(fp, "%d", sum);
    fclose(fp);

    return 0;
}
