/*����12-4���Ӽ�������10���ַ���д���ļ�f2.txt�У������¶�����������Ļ����ʾ��֤��*/

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i;
    char ch;
    FILE *fp;					/*  �����ļ�ָ��  */

    if((fp=fopen("f2.txt","w")) == NULL){	/*  ���ļ�f2.txt  */
         printf("File open error!\n"); 
	         exit(0);
    }
    for(i = 0; i < 10; i++){ 			/*  д�ļ�10��  */
        ch = getchar();
        fputc(ch, fp) ;
    }
    if(fclose(fp)){				/*  �ر��ļ�  */
        printf("Can not close the file!\n" );
        exit(0);
    }
    /* ������ʽ�ٴδ��ļ�f2.txt */
    if((fp=fopen("f2.txt","r")) == NULL){		
         printf("File open error!\n");
         exit(0);
    }
    for(i = 0; i < 10; i++){			/*  ���ļ�10��  */
        ch = fgetc(fp);
        putchar(ch);
    }
    if(fclose(fp)){				/*  �ٴιر��ļ�  */
        printf("Can not close the file!\n");
        exit(0);
    }
}
