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
	
	//����������λ�� ��mask����ʾ 
	while(t > 9) 
	{ 
		t /= 10;
		mask *= 10; //ȡ��һ��������λ�� Ȼ�����10  ��Щ�����˼· û�м��� 
	}
	
	//����һ������ ǰ�� ����һ��* 
	char *s[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	int d;
	while (mask > 0) 
	{
		d = n / mask;
		printf("%s", s[d]);
		if (mask > 9) 
			printf(" ");
		n %= mask;  //ȥ��������ֵ����λ 
		mask /= 10;  //maskλ�� Ҫ����10  ����һλ 
	}
	return 0;
}
