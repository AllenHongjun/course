/*����5-2�����5֮�ڵ����ֽ�������*/

#include <stdio.h>
int main(void)
{
	void pyramid(int n);

	pyramid(99);
	return 0;
}

void pyramid(int n)
{
	int i, j;
	for(i = 1; j <= n; i++){
		for(j =1; j<=n-i;j++)
			printf(" ");
		for(j = 1;j <=i; j++)
			printf(" %d ",i);
		putchar('\n');
	}
}





// /* ������ֽ����� */
// #include <stdio.h>
// int main(void)
// {   
// 	void pyramid(int n);					/* �������� */

// 	pyramid(5);								/* ���ú�����������ֽ����� */
// 	return 0;
// }

// void pyramid(int n)							/* �������� */
// {		
// 	int i, j;

// 	for(i = 1; i <= n; i++){				 ��Ҫ��������� 
// 		for(j = 1; j <= n-i; j++) 			/* ���ÿ����ߵĿո� */
// 			printf(" ");		        
// 		for(j = 1; j <= i; j++)  			/* ���ÿ�е����� ����ѧ�����רҵ��������� ����������� �ⶼû�и����  ʲô�ߴ��ϵĵ������̼����Զ��� ������*/ 
// 			printf(" %d ", i);	    
// 		putchar('\n');			    
// 	}
// }

