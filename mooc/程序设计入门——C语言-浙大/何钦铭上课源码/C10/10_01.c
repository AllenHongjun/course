/*����10-1�����һ������Բ��������ļ��������������ʽ����1��2��3���ֱ�ѡ��������塢Բ���塢Բ׶������������������������Ӧ������*/

/*  ����Բ����������������1���������壬2������Բ����3������Բ׶ */
#include <stdio.h>
#include <math.h>
#define  PI  3.141592654
void cal ( int sel );     /*  ��������  */
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
//һ��ʱ�� ��ֻ�ʺ�ѧϰһ�ſγ̻������ſγ̡���ѧ��һ����һ�š�����Ҫ̫����mooc��֤�� ��һ��һ�� ���߼���ʱ��ֻ�ʺ���һ������ ���ʺ϶������л�
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

/* ����������� V=4/3*PI*r*r*r  */
double vol_ball( )
{
	double r;

	printf("��������İ뾶��");
	scanf("%lf", &r);
	return(4.0/3.0*PI*r*r*r);
}
/*  ����Բ����� V=PI*r*r*h  */
double vol_cylind( )
{
	double r , h;

	printf("������Բ���ĵ�Բ�뾶�͸ߣ�");
	scanf("%lf%lf", &r, &h);
	return(PI*r*r*h);
}

/*  ����Բ׶��� V=h/3*PI*r*r  */
double vol_cone( )
{
	double r , h;

	printf("������Բ׶�ĵ�Բ�뾶�͸ߣ�");
	scanf("%lf%lf", &r,&h);
	return(PI*r*r*h/3.0);
}
