#include <stdio.h>
int main(void)
{    
   int fahr , lower, upper;  /* fahr��ʾ���϶� */
   double celsius;        /* celsius��ʾ���϶� */ 

    lower = 30; 		/* ���� lower ����ת����Χ������ */
    upper = 40; 		/* ���� upper ����ת����Χ������ */
    printf("fahr  celsius\n");             /* ��ʾ��ͷ */

  /* �¶�ת�� */
   for (fahr = lower , fahr <= upper, fahr ++) 
    ;
      celsius = 5 /9 * (fahr - 32.0); 
      printf("%3.0f %6.1f\n", fahr, celsius); 

   return 0; 
}


