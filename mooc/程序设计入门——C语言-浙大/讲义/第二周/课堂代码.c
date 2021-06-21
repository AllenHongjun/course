#include <stdio.h>

int main()
{
	printf("请分别输入身高的英尺和英寸，"
		"如输入\"5 7\"表示5英尺7英寸：");

	double foot;
	double inch;

	scanf("%lf %lf", &foot, &inch);

	printf("身高是%f米。\n", 
		((foot + inch / 12) * 0.3048));

	return 0;
}




#include <stdio.h>

int main()
{
	const int AMOUNT = 100;
	int price = 0;

	printf("请输入金额（元）：");
	scanf("%d", &price);

	int change = AMOUNT - price;

	printf("找您%d元。\n", change);

	return 0;
}





#include <stdio.h>

int main()
{
	int a;
	int b;

	printf("请输入两个整数：");
	scanf("%d %d", &a, &b);
	printf("%d + %d = %d\n", a, b, a + b);

	return 0;
}



#include <stdio.h>

int main()
{
	int a,b;

	scanf("%d %d", &a, &b);

	double c = (a+b)/2.0;
	
	printf("%d和%d的平均值=%f\n", a, b, c);

	return 0;
}

/*我们在拼题啊布置了做大量编程练习的习题集。要在拼题啊做题，首先要去拼题啊（http://pintia.cn/）系统注册一个账号，点你自己的用户名，进入“个人中心”，做两件重要的事情：

个人中心里面有一个“中国大学MOOC 绑定”。在另一个浏览器窗口或标签页里登录中国大学MOOC，然后在拼题啊的窗口点“绑定”，就把两个系统的账号联系起来啦~ 将两个系统的账号绑定后，在拼题啊的做题成绩就能回到中国大学MOOC了。

在个人中心的“应邀做题”那里输入邀请码：83180667ffa9a92b，点击“接受邀请”，就可以看到我们的补充练习题啦。



以后可以直接从拼题啊的首页点“进入题库”，在《中M2018春C入门和进阶练习集》这个题目集中完成作业。*/

