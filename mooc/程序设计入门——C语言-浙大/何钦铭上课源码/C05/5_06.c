/*����5-6���ڸ�������ж���ֲ�������*/


#include <stdio.h>
int main(void){
	int a;
	a =1;
	{
		int b =2;
		b = a+b;
		a =a+b;
	}
	printf("%d ",a);
}



// #include <stdio.h>
// int main(void)
// {  
//     int a;

//     a = 1;
//     {					/* ������俪ʼ */
//         int b = 2;		 �ֲ�����b�����÷�Χ�������ڸø�������� 
//         b = a + b;      
//         a = a + b;
// 	}					/* ���������� */
// 	printf("%d " , a );

// 	return 0;
// }
