//先求最大公约数，然后将分子分母同时除以最大公约数；  
#include <stdio.h>  
int main()  
{  
    int numerator,denominator,temp,a,b;  
    char c;  
    scanf("%d%c%d",&numerator,&c,&denominator);  
    a=numerator;  
    b=denominator;  
      
      //շת����� �����Ĺ�Լ��  �����㷨  
    while(b!=0){  
        temp=a%b;  
        a=b;  
        b=temp;  
        }  
    numerator/=a;  
    denominator/=a;  
    printf("%d/%d",numerator,denominator);  //ѧϰC���� ��Linux ϵͳ �о��� ������һ���ܴ�Ŀ�  ���ڵ�����ܶ�Ŀγ��Ҷ����úܺá�������ѧϰ  �ؼ�����ʲô�γ���ѧϰ�� ѧϰ����ѧϰ�ĺõĿγ� 
    return 0;  
}   
