/*����5-4�� ���뾫��e��ʹ�ø��������ʽ��еĽ���ֵ����ȷ�����һ��ľ���ֵС��e��Ҫ����͵��ú���funpi(e)��еĽ���ֵ��*/
                
/*  �ø��������ʽ����еĽ���ֵ������Ϊe  ��/4=1-1/3+1/5-1/7+*/

#include <stdio.h>
#include <math.h>
int main(void){
	double e,pi;
	double funpi(double e);

	printf("Enter e:");
	scanf("%lf", &e);
	pi = funpi(e);
	printf("pi = %.4f\n",pi);
	return 0;
}

double funpi(double e)
{
	int denominator ,flag;
	double item,sum;

	flag = 1;
	denominator = 1;
	item = 1.0;
	sum = 0;

	while(fabs(item) >= e){
		item = flag * 1.0 /denominator;
		sum = sum +item;
		flag = -flag;
		denominator = denominator +2;
	}
	return sum * 4;
}

// double funpi(double e)					/* �������pi�ĺ��� */
// {
// 		int denominator, flag; 
// 		double item, sum;

// 		flag = 1;       				/* flag ��ʾ�� i ��ķ��ţ���ʼΪ�� */
// 		denominator = 1;				/* denominator��ʾ�� i ��ķ�ĸ����ʼΪ1 */
// 		item = 1.0;        				/* item �д�ŵ� i ���ֵ����ֵȡ 1 */
// 		sum = 0;            			/* ���ۼӺ� pi �ĳ�ֵΪ0 */

//     /*  ��|item| �� eʱ��ִ��ѭ�� */
// 		while(fabs(item) >= e){   
// 			item = flag * 1.0 / denominator;    	/* ����� i ���ֵ */
// 			sum = sum + item;        				/* �ۼӵ� i ���ֵ */
// 			flag = -flag;   	 					/* �ı���ţ�Ϊ��һ��ѭ����׼�� */
// 			denominator = denominator + 2;			/* ��ĸ����2 ��Ϊ��һ��ѭ����׼�� */
// 		}
// 		return sum * 4;
// }


// #include <stdio.h>
// #include <math.h>
// int main(void)
// {
// 	   double e, pi;     				/* e ������   �����ÿһ�仰���н���  ���ҿ��Ե��� �����дҲ�淶 ������Ͻ�*/
// 	   double funpi(double e);			 �������� 

//     	printf("Enter e:");				/* ��ʾ�û����뾫�� */
// 	   	scanf("%lf", &e);
// 	   	pi = funpi(e);					/* ���ú������ѷ���ֵ��ֵ��pi */
// 		printf ("pi = %.4f\n", pi);
// 		return 0;
// }
// double funpi(double e)					/* �������pi�ĺ��� */
// {
// 		int denominator, flag; 
// 		double item, sum;

// 		flag = 1;       				/* flag ��ʾ�� i ��ķ��ţ���ʼΪ�� */
// 		denominator = 1;				/* denominator��ʾ�� i ��ķ�ĸ����ʼΪ1 */
// 		item = 1.0;        				/* item �д�ŵ� i ���ֵ����ֵȡ 1 */
// 		sum = 0;            			/* ���ۼӺ� pi �ĳ�ֵΪ0 */

//     /*  ��|item| �� eʱ��ִ��ѭ�� */
// 		while(fabs(item) >= e){   
// 			item = flag * 1.0 / denominator;    	/* ����� i ���ֵ */
// 			sum = sum + item;        				/* �ۼӵ� i ���ֵ */
// 			flag = -flag;   	 					/* �ı���ţ�Ϊ��һ��ѭ����׼�� */
// 			denominator = denominator + 2;			/* ��ĸ����2 ��Ϊ��һ��ѭ����׼�� */
// 		}
// 		return sum * 4;
// }

