/*����5-1������Բ���ĸߺͰ뾶����Բ�������volume=3.1415926*r*r*h��Ҫ����͵��ú���cylinder (r, h )����Բ���������� */


//�ȸ�ϰ ���۵�֪ʶ����һЩ�˵��� ����д���� �û���������� �Ÿոտ�ʼ  Ҫ���� ���� ����
//practice  practice  practice  !!!

#include <stdio.h>
int main(void)
{
	double height,radius,volume;
	double cylinder(double r,double h);  //������ԭ��

	printf("Enter radius and height: ");
	scanf("%lf%lf",&radius,&height);
	volume = cylinder(radius,height);
	printf("Volume = %.3f\n",volume);//����3λС��  %.3f С����ǰ��û��������������˼��  
	return 0;
}

//�����Ķ���
double cylinder(double r,double h)
{
	double result;
	result = 3.1415926 * r * r * h;
	return result;
}





