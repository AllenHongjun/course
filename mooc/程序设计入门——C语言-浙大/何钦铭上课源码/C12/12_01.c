/*����12-1���Ѷ̾�"Hello World!"���浽�����ļ�f1.txt�С�*/

/*���ַ���"Hello World!"���浽�ļ�f1.txt��*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;					/* �����ļ�ָ�� */

    if((fp=fopen("f1.txt","w")) == NULL){	/* ���ļ� */
   		printf("File open error!\n");
   		exit(0);
    }

    fprintf(fp,"%s","Hello World!");	        /* д�ļ� */    
    if(fclose(fp)){				/* �ر��ļ� */
        printf( "Can not close the file!\n" );
        exit(0);
    }

    return 0;
}


//��ǰ��Ŀ�� C���� ���ݽṹ pat��Ŀ �㷨��������
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	if((fp = fopen("f1.txt","w")) == NULL)
	{
		printf("File open error! \n");
		exit(0);
	}

	fprintf(fp,"%s","Hello World!");
	if(fclose(fp))
	{
		printf("Can not close the file! \n");
		exit(0);
	}
	return 0;
}

















