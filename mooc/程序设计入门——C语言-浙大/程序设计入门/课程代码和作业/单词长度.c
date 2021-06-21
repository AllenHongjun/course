#include <stdio.h>  
int main()  
{   int i=0;  
    char a;  
    while(1){  
    
    //感觉C语言很严谨 也可以说是有点刻板 呆板的 scanf 是 一个一个的从输入当中获取输入的数据 
        scanf("%c",&a);  
        if(a == '.'){  
                        if(i!=0){  
                                printf("%d",i);  
                        }  
                        printf("\n");  
                        break;  
                }  
        if(a==' '){  
                        if(i!=0){  
                                printf("%d ",i);  
                                i=0;  
                        }  
                }  
        else{  
                i+=1;  
        }  
    }  
return 0;  
}  
