/*����10-2���ٶ����ǰ���10-1��5�������ֱ�洢��2��.C�ļ��ϣ�Ҫ��ͨ���ļ���������������������*/

/*  ����Բ����������������1���������壬2������Բ����3������Բ׶ */
#include <stdio.h>
#include <math.h>
#define  PI  3.141592654
void cal ( int sel );     /*  ��������  */
#include  "prog2.c"
int main(void)
{
    int sel; 

/*  ѭ��ѡ�����Բ����������ֱ�������1��3������Ϊֹ  */
    while(1){			/* ����ѭ����ͨ��ѭ������ break ������ѭ�� */
		printf("  1-�����������\n");		
		printf("  2-����Բ�����\n");
		printf("  3-����Բ׶���\n");
		printf("  ����-�˳���������\n");
		printf("������������");  	/* ������ʾ*/
		scanf("%d", &sel);
		if (sel < 1|| sel > 3)			/* �����1��3�����֣�ѭ������  */
            break;     	
		else							/* ����1��3������cal()  */
            cal (sel);
	 }

	 return 0;
}

/*  ����Բ������������������غ���  */
void cal ( int sel )
{
	double  vol_ball(void);				/*  ��������  */
	double  vol_cylind(void);
	double  vol_cone(void );
	switch (sel) {
    	case 1: 		/*  ���������  */
			printf("�����Ϊ��%.2f\n",vol_ball());
			break;
        case 2:  		/*  ����Բ�����  */
			printf("Բ�����Ϊ��%.2f\n",vol_cylind( ));
			break;
        case 3:  		/*  ����Բ׶���  */
			printf("Բ׶���Ϊ��%.2f\n",vol_cone( ));
			break;
	}
}