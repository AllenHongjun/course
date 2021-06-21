#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	if (n < 0) 
	{ 
		printf("fu ");
		n = -n;
	}
	int t = n,mask = 1;
	
	//求出这个数的位数 用mask来表示 
	while(t > 9) 
	{ 
		t /= 10;
		mask *= 10; //取出一个整数的位数 然后乘以10  有些计算的思路 没有见过 
	}
	
	//定义一个数组 前面 加了一个* 
	char *s[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	int d;
	while (mask > 0) 
	{
		d = n / mask;
		printf("%s", s[d]);
		if (mask > 9) 
			printf(" ");
		n %= mask;  //去掉这个数字的最高位 
		mask /= 10;  //mask位数 要除以10  减少一位 
	}
	return 0;
}
