/* crashbox.dat是随机文件，记录金库消费流水帐记录信息 */
/* 程序的功能：添加新流水帐记录，查询金库最后余额 */
#include "stdio.h"
long size;            /*当前最近一次的流水号*/
struct LogData{       /*记录的结构*/
    long logid;       /*记录ID*/
    char logdate[11]; /*记录发生日期*/
    char lognote[15]; /*记录事件说明*/
    double charge;    /*发生费用：负-表示支出，正-表收入*/
    double balance;   /*余额*/
};

int inputchoice()     /*选择操作参数*/
{
    int mychoice;

    printf("\nEnter your choice:\n");
    printf("1 - Add a new cash LOG.\n2 - List All Cash LOG.\n");
    printf("3 - Query Last Cash LOG.\n0 - End program.\n ");
    scanf("%d",&mychoice);

    return mychoice;
}

long getLogcount(FILE *cfptr) /*获取文件记录总数*/
{		
    long begin,end,logcount;

    fseek(cfptr,0L,SEEK_SET);
    begin=ftell(cfptr);
    fseek(cfptr,size,SEEK_END);
    end=ftell(cfptr);
    logcount=(end-begin)/size-1;

    return logcount;
}

void ListAllLog(FILE *cfptr) /*列出所有收支流水帐*/
{
    struct LogData log;long logcount;

    fseek(cfptr,0L,SEEK_SET);  /*定位指针到文件开始位置*/
    fread(&log,size,1,cfptr);
    printf("logid  logdate   lognote             charge    balance\n");
    while(!feof(cfptr)){
        printf("%6ld %-11s %-15s %10.2lf %10.2lf\n",log.logid,log.logdate,log.lognote,log.charge,log.balance);
	fread(&log,size,1,cfptr);
    };
}

void QueryLastLog(FILE *cfptr) /*查询显示最后一条记录*/
{
    struct LogData log;long logcount;

    logcount=getLogcount(cfptr);
    if(logcount>0){     /* 表示有记录存在 */
        fseek(cfptr,size*(logcount-1),SEEK_SET);/*定位最后记录*/
	fread(&log,size,1,cfptr);/*读取最后记录*/
	printf("The last log is:\n");
	printf("logid:%-6ld\nlogdate:%-11s\nlognote:%-15s\n",log.logid,log.logdate,log.lognote);
	printf("charge:%-10.2lf\nbalance:%-10.2lf\n",log.charge,log.balance);        /*显示最后记录内容*/
    }
    else  
	printf("no logs in file!\n");	
}

void AddNewLog(FILE *cfptr) /*添加新记录*/
{
    struct LogData log,lastlog;
    long logcount;

    printf("Input logdate(format:2006-01-01):");
    scanf("%s",log.logdate);
    printf("Input lognote:");scanf("%s",log.lognote);
    printf("Input Charge:Income+ and expend-:");
    scanf("%lf",&log.charge);	
    logcount=getLogcount(cfptr);/*获取记录数*/
	
    if(logcount>0){
	fseek(cfptr,size*(logcount-1),SEEK_SET);
	fread(&lastlog,size,1,cfptr);/*读入最后记录*/
	log.logid=lastlog.logid+1;/*记录号按顺序是上次的号+1*/
	log.balance=log.charge+lastlog.balance;
    }
    else{  /*如果文件是初始，记录数为0*/
	log.logid=1;
	log.balance=log.charge;
    }
    rewind(cfptr);
    printf("logid= %ld\n",log.logid);
    fwrite(&log,sizeof(struct LogData),1,cfptr);/*写入记录*/
}

int main(void)
{
    FILE *fp;int choice;

    if((fp=fopen("cashbox.txt", "ab+")) == NULL){
	printf("can not open file cashbox.txt!\n");
	exit(0);
    }
    size = sizeof(struct LogData);
    while((choice=inputchoice())!=0){
        switch(choice){
	case 1:
	    AddNewLog(fp);break;
	case 2:
	    ListAllLog(fp);break;/*列出所有的收入支出情况*/
	case 3:
	    QueryLastLog(fp);break;/*查询最后的余额*/
	default:
	    printf("Input Error.");break;
	}
    }
    fclose(fp);

    return 0;
}
