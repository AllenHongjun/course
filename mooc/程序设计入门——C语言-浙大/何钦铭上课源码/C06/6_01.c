/*����6-1��������İ뾶��������ı�����������*/


#include <stdio.h>
#define PI 3.14
int main(void)
{
    double r,s,v;
    printf("intput r:");
    scanf("%lf",&r);
    s = 4.0 * PI * r * r;
    v = 4.0/3.0 * PI * r * r * r;
    printf("s = %f, v = %f\n",s,v);
    return 0;
}



