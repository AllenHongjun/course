/*【例12-4】从键盘输入10个字符，写到文件f2.txt中，再重新读出，并在屏幕上显示验证。*/

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i;
    char ch;
    FILE *fp;					/*  定义文件指针  */

    if((fp=fopen("f2.txt","w")) == NULL){	/*  打开文件f2.txt  */
         printf("File open error!\n"); 
	         exit(0);
    }
    for(i = 0; i < 10; i++){ 			/*  写文件10次  */
        ch = getchar();
        fputc(ch, fp) ;
    }
    if(fclose(fp)){				/*  关闭文件  */
        printf("Can not close the file!\n" );
        exit(0);
    }
    /* 按读方式再次打开文件f2.txt */
    if((fp=fopen("f2.txt","r")) == NULL){		
         printf("File open error!\n");
         exit(0);
    }
    for(i = 0; i < 10; i++){			/*  读文件10次  */
        ch = fgetc(fp);
        putchar(ch);
    }
    if(fclose(fp)){				/*  再次关闭文件  */
        printf("Can not close the file!\n");
        exit(0);
    }
}
