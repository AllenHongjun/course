#include <stdio.h>
#include <math.h>

int main(void){
	
	int input_num;//输入的数字
	int n=1;  //表示数字在第几位数 
	int a,b;
	int c=0; //这个数表示二级制的数字
	int d,e;
	int f = 0;
	int j =0; 

	scanf("%d",&input_num);
	a = b = input_num;
	do{	
	
		b = a%10;
		a = a/10;
		
		if(n%2 == b%2){
			c = c + 1*pow(10,n-1); 
		}
		n++; 		
	}while(a != 0);
	
	//将二进制数转为十进制数
	
	do{
		d=c %10;
		c = c/10;
		f = f+d*pow(2,j);
		j++;
	}while(c!=0); 
	 
	printf("%d",f);	 
} 
