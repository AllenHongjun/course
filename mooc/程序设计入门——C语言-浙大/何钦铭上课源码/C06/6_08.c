/*【例6-8】输入一行字符，将其中的大写字母转换为相应的小写字母后输出，小写字母转换为相应的大写字母后输出，其他字符按原样输出。*/


#include <stdio.h>
int main(void){

  char ch;
  printf("input charcters: ");
  ch = getchar();//计算机我要读取一个字符

  while(ch != '\n'){

    if (ch >='A' && ch <= 'Z')
    {
      ch = ch -'A' + 'a';
    }else if(ch >= 'a' && ch <='z'){
      ch = ch - 'a' +'A';
    }
    putchar(ch);
    ch = getchar();
  }

  return 0;
}


/* 大小写英文字母转换 */
// #include <stdio.h>
// int main(void)
// {

//   //格式话字符串 输出
//    char ch;                      	/* 定义1个字符变量ch */

//    printf("input characters: ");   	/* 输入提示 */
//    ch = getchar();              	/* 第8行，输入一个字符，赋给变量 ch */
//    /* 比较ch和 '\n'，当输入的字符不是回车时，继续循环；遇回车，则循环结束 */
//    while(ch != '\n'){
//       if ( ch >= 'A' && ch <= 'Z' )    	/* 如果ch是大写字母 */
//           ch = ch - 'A' + 'a';   		/* 大写字母转换为小写字母 */
//       else if ( ch >= 'a' && ch <= 'z')	/* 如果ch是小写字母 */
//           ch = ch - 'a' + 'A';       	/* 小写字母转换为大写字母  关键理解a AA在前面 然后两个字符固定都是相差32 */
//       putchar(ch);             	        /* 输出转换后的字符 */
//       ch = getchar();           	/* 第16行，读入下一个字符 */
//    }                           	        /* 第17行 */

//    return 0;
// }
