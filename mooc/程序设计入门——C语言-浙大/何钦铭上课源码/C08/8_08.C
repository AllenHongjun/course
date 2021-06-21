/*
【例8-8】输入年份和天数，输出对应的年、月、日。要求定义和调用函数month_day ( year, yeardy, *pmonth, *pday)，其中year是年，yearday是天数，*pmonth和*pday是计算得出的月和日。例如，输入2000和61，输出2000-3-1，即2000年的第61天是3月1日。
*/

/*  使用指针作为函数参数返回多个函数值的示例 */
# include <stdio.h>
int main (void)
{
    int day, month, year, yearday;             /*  定义代表日、月、年和天数的变量*/
    void month_day(int year,int yearday, int *pmonth,int *pday);/*声明计算月、日的函数*/

    printf("input year and yearday: ");	       /* 提示输入数据：年和天数 */
    scanf ("%d%d", &year, &yearday );		
    month_day (year, yearday, &month, &day );  /* 调用计算月、日函数  */ 
    printf ("%d-%d-%d \n", year, month, day );	

    return 0;	
}
void month_day ( int year, int yearday, int * pmonth, int * pday)
{
    int k, leap;
    int tab [2][13]= {
       {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    };  /* 定义数组存放非闰年和闰年每个月的天数 */

    leap=year%4==0 && year% 100!= 0 || year%400==0; /* 建立闰年判别条件leap */
          /* 如果leap＝1，表示为闰年，从tab[1][k]中取k月的天数；否则为非闰年  */
   
    for ( k=1; yearday>tab[leap][k]; k++)
        yearday -= tab [leap][k];
    * pmonth = k;
    *pday = yearday;
}
