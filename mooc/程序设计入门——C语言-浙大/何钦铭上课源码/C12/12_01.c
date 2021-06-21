/*【例12-1】把短句"Hello World!"保存到磁盘文件f1.txt中。*/

/*把字符串"Hello World!"保存到文件f1.txt中*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;					/* 定义文件指针 */

    if((fp=fopen("f1.txt","w")) == NULL){	/* 打开文件 */
   		printf("File open error!\n");
   		exit(0);
    }

    fprintf(fp,"%s","Hello World!");	        /* 写文件 */    
    if(fclose(fp)){				/* 关闭文件 */
        printf( "Can not close the file!\n" );
        exit(0);
    }

    return 0;
}


//当前的目标 C语言 数据结构 pat题目 算法设计与分析
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

















