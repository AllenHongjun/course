/*【例3-5】求解简单表达式。输入一个形式如“操作数 运算符 操作数”的四则运算表达式，输出运算结果。*/


/*求解简单的四则运算表达式 */
#include <stdio.h>
int main(void)
{
    double value1, value2;
    char operator1;
    printf("Type in an expression: ");    /* 提示输入一个表达式  这里  oprator 是一个关键字 要注意  修改一下 不用使用关键字来作为变量名  编译的时候 错误提示 */
    scanf("%lf%c%lf", &value1, &operator1, &value2);
    switch(operator1){
        case '+': 
            printf("%.2f\n", value1+value2);
            break;
        case '-': 
            printf("%.2f\n", value1-value2);
            break;
        case '*': 
            printf("%.2f\n", value1*value2);
            break;
        case '/': 
            printf("%.2f\n", value1/value2);
            break;
        default:  
            printf("Unknown operator\n");
            break;
    }

    return 0;
}


/*
//语言先学高级语言 学后台发展起来的语言 学更加流行的语言  计算机语言 本质是一条条命令的组合 让计算机 按照你的 指令来执行 而不是和计算机交流
int test(void){
	double value1,value2;
	char operator;
	printf("Type in an expression:");//xie dai ma de shihou  yao mingque de zhidao  zhiji shi zai xie sm chong renshi  dao wanquan de shulian 
	scanf("%lf%c%lf",&value1,&operator, &value2);
	switch(operator){
		case '+':
			printf("%.2f\n",value1 + value2);
			break;
		case '-':
			printf("%.2f\n",value1 - value2);
			break;
		case '*':
			printf("%.2f\n",value1 * value2);
			break;
		case '/':
			printf("%.2f\n",value1 / value2);
			break;
		default:
			printf("Unkonwn operator \n");
			break;


	}

	return 0 ;
}
*/