//指针  结构  链表 程序 结构  写代码的手感
//我的代码 测试 写手感的时候 使用

#include <stdio.h>

int main(void)
{
	double a[2], *p, *q;

	p = &a[0];
	q = p + 1;
	printf("%d\n",q - p);

	printf("%x\n",q);
	printf("%p\n",q);

	return 0;
}



//----------------
#include <stdio.h>
int main(void)
{

	int a, a[10], *p;
	long sum = 0;
	printf("Enter 10 integers: ");
	for(i = 0; i < 10; i++)
		scanf("%d",&a[i]);
	for(p = a; p < a+9; p++)
		sum = sum + *p;
	printf("sum = %ld \n",sum);
	return 0;
}


//***********8_13

#include <stdio.h>
int main(void)
{
	int i, a[10], *p;
	long s = 0;
	int sum(int a[], int n);

	printf("Enter 10 integers: ");

	for(i = 0; i<10; i++)
		scanf("%d",&a[i]);
	s = sum(a ,10);
	printf("sum = %ld \n",s);
	return 0;
}

//这里的数组 和main函数的中 数组 是同一个东西。如果修改会修改主函数中的数组
int sum(int a[], int n){
	int i, s = 0;
	for( i = 0; i < n; ++i)
		s += a[i];

	return s;
}



//*****8——14
#include <stdio.h>
#include <string.h>
#define MAXLINE 100

void encrypt (char *);

int main(void)
{	
	char line [MAXLINE]; //定义一个字符数组
	printf("Input the string:");
	gets(line); //这个函数是怎么用的 
	encrypt(line);
	printf("%s%s\n","After being encrypt: ", line);


	return 0;
}

//数组的指针 这个指针指向的是一个字符串
void encrypt (char *s)
{

	for( ; *s ! = '\0'; s++)
		if( *s == 'z')
			*s = 'a';
		else
			*s = *s+1;
}


//*******8_16
#include <stdio.h>
#include <string.h>

//输入 5个 字符串 算出 最小的那个字符串
int main(void)
{	

	int i;
	char sx[80], smin[80];

	scanf("%s",sx);
	strcpy(smin,sx);
	for(i=1; i<5; i++){
		scanf("%s",sx);
		if(strcmp(sx,smin) <0)
			strcpy(smin,sx);
	}
	printf("min is %s\n",smin);
	return 0;
}


//****8_17
#include <stdio.h>
#include <stdio.h>

int main()
{
	int n, sum, i, *p;
	printf("Enter n: ");
	scanf("%d",&n);

	if ((p = (int *)calloc(n, sizeof(int))) == NULL)
	{
		printf("Not able to allcoate memory. \n");
		exit(1);
	}

	printf("Enter %d integers: ", n);
	for(i = 0; i <n; i++)
		scanf("%d", p +i);

	sum = 0;

	for(i = 0; i < n; i++)
		sum = sum + *(p+i);

	printf("The sum is %d \n", sum);
	free(p);
	return 0;
}
