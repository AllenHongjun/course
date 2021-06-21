/*【例12-5】将字符串"apple","grape","pear"写入到磁盘文件f12-5.txt中，然后再从该文件中读出，显示到屏幕。*/

/*把字符串"apple","grape","pear"保存到文件f12-5.txt中*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    FILE *fp;						/*1、定义文件指针 */
	char a[][80]={"apple","grape","pear"},strout[80]="";
	int  i;

    if((fp=fopen("f12-5.txt","w")) == NULL){		/*2、打开文件  */
   	printf("File open error!\n");
   	exit(0);
    }
    for(i=0;i<3;i++){					/*3、写文件  */	
        fputs(a[i],fp);
    }
    if(fclose(fp)){					/*4、关闭文件  */
	printf("Can not close the file!\n");
	exit(0);
    }
    if((fp=fopen("f12-5.txt","r")) == NULL){		/*5、再次打开文件  */
   	printf("File open error!\n");
   	exit(0);
    }
    i=0;
    while(!feof(fp)){
	if(fgets(strout,strlen(a[i++])+1,fp)!=NULL)	/*6、读文件  */
	    puts(strout);
    }
    if(fclose(fp)){					/*7、关闭文件  */
	printf("Can not close the file!\n");
	exit(0);
    }	 

    return 0;
}
