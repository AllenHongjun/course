/*����12-3����֪һ���ı��ļ�f1.txt���뽫���ļ�����һ�ݣ�����Ϊf2.txt��*/
/*�½�һ���ı��ļ�f1.dat�������ļ���Դ�������ͬһĿ¼�£�ִ�г��򣬹۲�����*/

#include <stdio.h>
int main(void)
{
   FILE *fp1,*fp2;
   char c;
	   
   if((fp1=fopen("f1.txt","r"))==NULL){
	printf(" File open error!\n");
	exit(0);
   }
   if((fp2=fopen("f2.txt","w"))==NULL){
	printf(" File open error!\n");
	exit(0);
   }
   while(!feof(fp1)){
	c=fgetc(fp1);
	fputc(c,fp2);
   }
   fclose(fp1);
   fclose(fp2);

   return 0;
}


#include <stdio.h>
int main(void)
{
	FILE *fp1, *fp2;
	char c;
	if( (fp1 = fopen("f1.txt","r")) == NULL){
		printf(" File open error! \n");
		exit(0);
	}

	if( (fp2 = fopen("f2.txt","w")) == NULL){
		printf(" File open error! \n");
		exit(0);
	}

	while( !feof(fp1)){
		c = fgetc(fp1);
		fputc(c,fp2);
	}
	fclose(fp1);
	fclose(fp2);

	return 0;
}


