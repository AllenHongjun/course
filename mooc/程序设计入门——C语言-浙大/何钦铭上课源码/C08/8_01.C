/*【例8-1】利用指针模拟寻找保险箱密码的故事。*/

/*  获取密码的两种方法 */



#include <stdio.h>
int main(void)
{	

	//80%的时间花费在重要而不紧急的事情上面  认准了的正确的目标要坚持  不切实际的目标要放弃
	int key = 911;
	int *addr = NULL;

	addr = &key;

	printf("The key is %d\n",key);

	printf("If I konw the address of the key,I also can get it : %d\n",*addr);

}

// #include <stdio.h>
// int main(void)
// {
//     int key=911;       /* 变量key存放密码 */
//     int *addr=NULL;    /* 变量addr存放地址  1.指针变量的意思 里面存放地址  int *addr=Null  */

//     addr=&key;        将key的地址赋给addr  2. 定义 复制  和使用  3 *addr 取出来的不是 地址 而是这个地址指向的那个值 这个真的有点变态呀

//     /* 通过key变量名输出密码值   定义  赋值  取值  一个中文有多个意思  要注意区分*/
//     printf("The key is: %d\n", key);   
//     /* 通过key变量地址来输出密码值 */
//     printf("If I know the address of the key, I also can get it: %d\n", *addr);

//     return 0;
// }

