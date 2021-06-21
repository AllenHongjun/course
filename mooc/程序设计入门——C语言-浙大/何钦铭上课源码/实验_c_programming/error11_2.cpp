#include <stdio.h>
float matrix(float *a[3], int n)
{
    int i, j;
    float sum = 0;
 
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++){
	    if(i == j)
		sum = sum + *(*(a + i) + j);
	    if(j == 2-i && i != j)
		sum = sum + *(*(a + i) + 2 - i);
	}

    return sum;
}

int main(void)
{
    int i,j; 
    float a[3][3];

    printf("ÊäÈë3¡Á3Êý×é\n");
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
	    scanf("%f", &a[i][j]);
    printf("sum=%0.2f \n", matrix(a,3));

    return 0;
}
