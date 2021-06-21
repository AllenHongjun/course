/*【例7-8】自定义1个函数day_of_year(year, month, day)，
计算并返回year(年)、month(月)和day(日)对应的是该年的第几天。*/

// #include <stdio.h>
// int day_of_year(int year, int month, int day);
// int main(void)
// {
//     int year, month, day;
	
//     printf("Input year, month, day:");
//     scanf("%d%d%d", &year,&month, &day);
//     printf("day=%d\n", day_of_year(year, month, day));

//最想的两件事就是把 选修的 这几门课 好好的学习争取拿到优秀的整数  C语言写代码的能力 多多提高
//     return 0;     
// }

#include <stdio.h>
int main(void)
{
    int year , month, day;
    printf("Input year, month,day:");
    scanf("%d%d%d",&year,&month,&day);
    printf("day=%d\n",day_of_year(year,month,day));

    return 0;
}

int day_of_year(int year, int month, int day)
{
    int k,leap;
    int tab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 30, 31},
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 30, 31},
    };
    /* 判断year是否为闰年，当year是闰年时，leap=1；当year是非闰年时，leap=0 */
    leap = (year % 4 == 0 && year % 100 !=0 || year %400 == 0);
    for(k = 1; k< month; k++)
        day = day +tab[leap][k];

    return day;
}

/* 计算某个日期对应该年的第几天 */
// int day_of_year(int year, int month, int day)
// {
//     int k, leap;
//     int tab[2][13] = {    /* 数组初始化，将每月的天数赋给数组 */
//         {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
//         {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
//     };

//     /* 判断year是否为闰年，当year是闰年时，leap=1；当year是非闰年时，leap=0 */
//     leap = (year % 4 == 0 && year%100!=0 || year%400==0); 

//     /* 计算天数 */
//     for(k = 1; k < month; k++)
//        day = day + tab[leap][k];

//     return day; 
// }    
