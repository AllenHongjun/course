/*【例6-4】已知字符 'b' 的ASCII码值是98，'A' 的ASCII码值是65，写出下列程序的运行结果。*/
                
//ascii 码是上面意思  abc ABC  大写字母在前面 小写在后
/* 按字符形式或整数形式输出字符型数据示例 */


//要搞清楚 这一张你要学习上面  你学的怎么样  你的目的达到了 不忘初心2 放的始终  学习 mooc 是了进入外企  赚钱环游世界  途径就是  pat考试 he  托福考试
#include <stdio.h>

int main(void)
{

	char ch ='b';
	printf("%c,%d\n",'b','b');
	printf("%c,%d\n",98,98);
	printf("%c,%d\n",97,'b'-1);
	printf("%c,%d\n",ch-'a'+'A',ch-'a'+'A');//小写 转换为大写字母这个字母理解  大小写字母相差32个字符 也就是 'a' - 'A'  'a'-32 ='A'   'B'+32 = 'b'  先大写字母 然后再是小写字母
	printf("%d,%d\n",'a','A');//97,65   A在前面
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
