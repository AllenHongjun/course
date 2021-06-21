/*【例12-2】已知一个文本文件f.txt中保存了5个学生的计算机等级考试成绩，包括学号、姓名和分数，文件内容如下： */
/*	301101 张文 		91	*/
/*	301102 陈慧 		85	*/
/*	301103 王卫东		76	*/
/*	301104 郑伟 		69	*/
/*	301105 郭温涛	 	55	*/

/*请将文件的内容读出并显示到屏幕中。*/
#include "stdio.h"
int main(void)
{
   FILE *fp;					/* 定义文件指针*/
   long num;
   char stname[20];
   int  score;

   if((fp=fopen("f.txt","r")) == NULL){	/* 打开文件  */
	printf("File open error!\n");
	exit(0);
    }

    while(!feof(fp)){
       fscanf(fp,"%ld%s%d",&num,stname,&score);		/* fscanf函数将数据读入*/
       printf("%ld	%s %d\n",num,stname,score);	/* 输出到屏幕*/
    };

    if(fclose(fp)){					/* 关闭文件 */
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




