/*����6-2��ʹ�û�����ʽ����˵��%d��%o��%x��������������ݡ�*/

/* �� %o ������������ʾ�� */

#include <stdio.h>
int main(void)
{

	int a,b;
	printf("input a,b: ");
	scanf("%o%d",&a,&b);  //��ʽ�������ַ���  ��Ҫ��������������   
	printf("%d %5d\n",a,b);  //ͳ����������  ��Ҫ����һ��ִ����  �м�Ŀո����� %5d ��ʾ����5���ַ��ĳ��������
}




// #include <stdio.h>    
// int main(void)
// {   
//     int a, b;    

//     printf("input a, b: ");
//     scanf("%o%d", &a, &b); 
//     printf("%d %5d\n", a, b);   //%5dָ������b��������Ϊ5 

//     return 0;
// }


// int test(void)
// {
// 	int a, b;
// 	printf("input a, b: \n");
// 	scanf("%o%d",&a ,&b); 
// 	printf("%d %5d\n", a,b);

// 	return 0 ;
// }
