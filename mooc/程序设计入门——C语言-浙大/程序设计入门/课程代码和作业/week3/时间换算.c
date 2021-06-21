#include <stdio.h>
 int main(int argc, char const *argv[])
{
	//时间换算题目 
    int bjt_time;
	int utc_time;
	
	int a,b,c;
	
	int d; 
	scanf("%d",&bjt_time);
	
	
	a = bjt_time%100;   //小时部分 
	b = bjt_time/100;   //分钟部分
	
	//注意有一个跨日运行
	 
	d = b-8;
	if(d < 0){
		d = d+24;
	}
	
	utc_time = d*100+a;
	printf("%d",utc_time);
	 


	
	return 0;
}





//有些看起来很难的事情 。其实很简单  有些  看起来 很难的事情。其实很简单 
//int main()  
//{  
//    int utc , bjt;  
//    int hour, minute;  
//  
//    scanf("%d", &bjt);  
//    //转换获得的bjt变为分开的小时与分钟  
//    hour = bjt / 100;  
//    minute = bjt % 100;   
//    //通过utc=bjt-8换算，并注意跨日运算   
//    int ih = hour - 8;  
//    if ( ih <0 ) {  
//        ih = 24 + ih;  
//    }  
//    //将 分开的小时和分钟转换回整数；   
//    utc = ih*100+minute;   
//      
//    printf("%d\n", utc);  
//      
//    return 0;  
//}  
