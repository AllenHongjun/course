#include <stdio.h>
int main(void){
	
	int odd_num=0;
	int even_num=0;
	int input_num;
	
	do{
		scanf("%d",&input_num);
		if(input_num%2 ==1)  //注意这里 -1 除以2的话 余数是 -1 所以 odd 会加加  编程难在定位问题的地方。。难在思考问题的解决办法。 保存好已经写好的代码 
		{
			even_num++;	
		}else{
			odd_num++;
		}
	}while(input_num!=-1);
	printf("%d %d",even_num,odd_num-1);
	return 0 ; 
	
} 
