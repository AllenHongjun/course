/*����12-5�����ַ���"apple","grape","pear"д�뵽�����ļ�f12-5.txt�У�Ȼ���ٴӸ��ļ��ж�������ʾ����Ļ��*/

/*���ַ���"apple","grape","pear"���浽�ļ�f12-5.txt��*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    FILE *fp;						/*1�������ļ�ָ�� */
	char a[][80]={"apple","grape","pear"},strout[80]="";
	int  i;

    if((fp=fopen("f12-5.txt","w")) == NULL){		/*2�����ļ�  */
   	printf("File open error!\n");
   	exit(0);
    }
    for(i=0;i<3;i++){					/*3��д�ļ�  */	
        fputs(a[i],fp);
    }
    if(fclose(fp)){					/*4���ر��ļ�  */
	printf("Can not close the file!\n");
	exit(0);
    }
    if((fp=fopen("f12-5.txt","r")) == NULL){		/*5���ٴδ��ļ�  */
   	printf("File open error!\n");
   	exit(0);
    }
    i=0;
    while(!feof(fp)){
	if(fgets(strout,strlen(a[i++])+1,fp)!=NULL)	/*6�����ļ�  */
	    puts(strout);
    }
    if(fclose(fp)){					/*7���ر��ļ�  */
	printf("Can not close the file!\n");
	exit(0);
    }	 

    return 0;
}
