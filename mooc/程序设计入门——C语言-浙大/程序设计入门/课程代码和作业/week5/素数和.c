
#include <stdbool.h>
#include <stdio.h>


/*

* 将问题转化 为思路  1.知道 什么样的数字 是素数。。2.将m,n之间的素数按顺序的放到 一个数组当中去 3.用for循环 求出 这个和
* 数组的定义 。还有一个血 语法 细节的注意 这个就是要熟练了。。熟悉编程的手感。。还有解决问题的能力。。为学习数据结构做好准备 
*/ 
bool isPrime(int number)
{	
    int i =2;
			//判断一个数 是不是素数 
    for(i = 2; i < number; ++i)
        if(!(number % i))
            return false;
    return true;
}
 
int main(void)
{
    int n, m, sum = 0; //如果有思路的话 代码 就比较好写了。 
    int prime[200] = {0, 2};//定义一个数组 
    int i =3,cnt=2; 
    scanf("%d%d", &n, &m);
    for(i = 3, cnt = 2; cnt <= m; ++i)
        if(isPrime(i))
            prime[cnt++] = i;
    for(cnt = n; cnt <= m; ++cnt)
        sum += prime[cnt];
    printf("%d\n", sum);
 
    return 0;
}
