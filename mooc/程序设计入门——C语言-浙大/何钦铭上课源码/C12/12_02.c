/*����12-2����֪һ���ı��ļ�f.txt�б�����5��ѧ���ļ�����ȼ����Գɼ�������ѧ�š������ͷ������ļ��������£� */
/*	301101 ���� 		91	*/
/*	301102 �»� 		85	*/
/*	301103 ������		76	*/
/*	301104 ֣ΰ 		69	*/
/*	301105 ������	 	55	*/

/*�뽫�ļ������ݶ�������ʾ����Ļ�С�*/
#include "stdio.h"
int main(void)
{
   FILE *fp;					/* �����ļ�ָ��*/
   long num;
   char stname[20];
   int  score;

   if((fp=fopen("f.txt","r")) == NULL){	/* ���ļ�  */
	printf("File open error!\n");
	exit(0);
    }

    while(!feof(fp)){
       fscanf(fp,"%ld%s%d",&num,stname,&score);		/* fscanf���������ݶ���*/
       printf("%ld	%s %d\n",num,stname,score);	/* �������Ļ*/
    };

    if(fclose(fp)){					/* �ر��ļ� */
        printf( "Can not close the file!\n" );
        exit(0);
    }
}

#include "stdio.h"
int main(void)
{
	FILE *fp;
	long num;
	char stname[20];
	int score;

	if( (fp = fopen("f.txt","r")) == NULL){
		printf("File open error! \n");
		exit(0);
	}

	while(!feof(fp)){
	
		fscanf(fp,"%ld%s%d",&num,stname,&score);
		printf("%ld %s %d\n",num,stname,score);
	}
	if(fclose(fp)){
		printf(" Can not close the file! \n");
	}

}




