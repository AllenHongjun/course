#include <stdio.h>
 int main(int argc, char const *argv[])
{
	//ʱ�任����Ŀ 
    int bjt_time;
	int utc_time;
	
	int a,b,c;
	
	int d; 
	scanf("%d",&bjt_time);
	
	
	a = bjt_time%100;   //Сʱ���� 
	b = bjt_time/100;   //���Ӳ���
	
	//ע����һ����������
	 
	d = b-8;
	if(d < 0){
		d = d+24;
	}
	
	utc_time = d*100+a;
	printf("%d",utc_time);
	 


	
	return 0;
}





//��Щ���������ѵ����� ����ʵ�ܼ�  ��Щ  ������ ���ѵ����顣��ʵ�ܼ� 
//int main()  
//{  
//    int utc , bjt;  
//    int hour, minute;  
//  
//    scanf("%d", &bjt);  
//    //ת����õ�bjt��Ϊ�ֿ���Сʱ�����  
//    hour = bjt / 100;  
//    minute = bjt % 100;   
//    //ͨ��utc=bjt-8���㣬��ע���������   
//    int ih = hour - 8;  
//    if ( ih <0 ) {  
//        ih = 24 + ih;  
//    }  
//    //�� �ֿ���Сʱ�ͷ���ת����������   
//    utc = ih*100+minute;   
//      
//    printf("%d\n", utc);  
//      
//    return 0;  
//}  
