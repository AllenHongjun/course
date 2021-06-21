/*【例12-3】已知一个文本文件f1.txt，请将该文件复制一份，保存为f2.txt。*/
/*新建一个文本文件f1.dat，将该文件与源程序放在同一目录下，执行程序，观察结果。*/

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


