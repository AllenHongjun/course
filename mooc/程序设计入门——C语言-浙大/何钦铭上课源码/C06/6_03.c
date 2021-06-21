/*【例6-3】输入输出字符。*/

/* 调用scanf和printf输入输出字符示例 */


//想一下 这辈子你想敲多少代码 1万   10 万  100万   1000万  ----》敲到一定的数量之后  再考虑别的问题把
#include <stdio.h>
 int main(void)

 {

 		//听老师将 大概能明白  自己抄一遍 理解更加清楚  pta的题目完整 就是熟练。。还要多多的应用
 	char ch1,ch2,ch3;
 	scanf("%c%c%c",&ch1,&ch2,&ch3);

 	printf("%c%c%c%c%c",ch1,'#',ch2,'#',ch3);//这里注意C语言里面空格 也是一个字符会输出
 }





// #include <stdio.h> 
// int main(void)
// {   
//     char ch1, ch2, ch3;

//     scanf("%c%c%c",&ch1, &ch2, &ch3); //注意这里是11对应的  %c对应的就是 ch1 ch2 对应的就是 ch2
//     printf("%c%c%c%c%c",ch1, '#', ch2, '#', ch3);    
// }
