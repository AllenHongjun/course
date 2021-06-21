//å…ˆæ±‚æœ€å¤§å…¬çº¦æ•°ï¼Œç„¶åå°†åˆ†å­åˆ†æ¯åŒæ—¶é™¤ä»¥æœ€å¤§å…¬çº¦æ•°ï¼›  
#include <stdio.h>  
int main()  
{  
    int numerator,denominator,temp,a,b;  
    char c;  
    scanf("%d%c%d",&numerator,&c,&denominator);  
    a=numerator;  
    b=denominator;  
      
      //Õ·×ªÏà³ı·¨ Çó×î´óµÄ¹«Ô¼Êı  ¾ßÌåËã·¨  
    while(b!=0){  
        temp=a%b;  
        a=b;  
        b=temp;  
        }  
    numerator/=a;  
    denominator/=a;  
    printf("%d/%d",numerator,denominator);  //Ñ§Ï°CÓïÑÔ ºÍLinux ÏµÍ³ ¸Ğ¾õÊÇ µô½øÁËÒ»¸öºÜ´óµÄ¿Ó  ÏÖÔÚµÄÎÊÌâºÜ¶àµÄ¿Î³ÌÎÒ¶¼¾õµÃºÜºÃ¡£¡£¶¼ÏòÑ§Ï°  ¹Ø¼üÊÇÄãÊ²Ã´¿Î³ÌÄÜÑ§Ï°µÄ Ñ§Ï°ÄãÄÜÑ§Ï°µÄºÃµÄ¿Î³Ì 
    return 0;  
}   
