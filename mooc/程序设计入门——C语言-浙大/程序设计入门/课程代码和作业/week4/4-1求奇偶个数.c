#include <stdio.h>
int main(void){
	
	int odd_num=0;
	int even_num=0;
	int input_num;
	
	do{
		scanf("%d",&input_num);
		if(input_num%2 ==1)  //ע������ -1 ����2�Ļ� ������ -1 ���� odd ��Ӽ�  ������ڶ�λ����ĵط���������˼������Ľ���취�� ������Ѿ�д�õĴ��� 
		{
			even_num++;	
		}else{
			odd_num++;
		}
	}while(input_num!=-1);
	printf("%d %d",even_num,odd_num-1);
	return 0 ; 
	
} 
