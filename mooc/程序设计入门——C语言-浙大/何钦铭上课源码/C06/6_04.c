/*【例6-4】已知字符 'b' 的ASCII码值是98，'A' 的ASCII码值是65，写出下列程序的运行结果。*/
                
//ascii 码是上面意思  abc ABC  大写字母在前面 小写在后
/* 按字符形式或整数形式输出字符型数据示例 */

#include <stdio.h>

int main(void)
{

	char ch ='b';
	printf("%c,%d\n",'b','b');
	printf("%c,%d\n",98,98);
	printf("%c,%d\n",97,'b'-1);
	printf("%c,%d\n",ch-'a'+'A',ch-'a'+'A');
	printf("%d,%d\n",'a','A');
	return 0;
}



// #include <stdio.h>       
// int main(void)
// {   
//     char ch = 'b';
//     //很多的问题 你敲一遍代码就能明白了 你代码敲的多了 自然而然的就会写。别人的代码 也就看的懂了。
//     //我真的发掘 敲代码 比玩游戏还有意思欸  哈哈哈 哈  加油咯




//     printf("%c,%d\n", 'b', 'b');  	 分别按字符形式和整数形式输出字符 'b'  
//     printf("%c,%d\n", 98, 98); 		/* 分别按字符形式和整数形式输出整数 98 */
//     printf("%c,%d\n", 97, 'b' - 1);	/* 计算 'b' - 1的结果为 'a' */
//     printf("%c,%d\n", ch - 'a' + 'A', ch - 'a' + 'A'); /* 将小写字母转换为大写字母后输出*/

//     return 0;
// }
