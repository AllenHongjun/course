
#include <stdbool.h>
#include <stdio.h>


/*

* ������ת�� Ϊ˼·  1.֪�� ʲô�������� ����������2.��m,n֮���������˳��ķŵ� һ�����鵱��ȥ 3.��forѭ�� ��� �����
* ����Ķ��� ������һ��Ѫ �﷨ ϸ�ڵ�ע�� �������Ҫ�����ˡ�����Ϥ��̵��ָС������н���������������Ϊѧϰ���ݽṹ����׼�� 
*/ 
bool isPrime(int number)
{	
    int i =2;
			//�ж�һ���� �ǲ������� 
    for(i = 2; i < number; ++i)
        if(!(number % i))
            return false;
    return true;
}
 
int main(void)
{
    int n, m, sum = 0; //�����˼·�Ļ� ���� �ͱȽϺ�д�ˡ� 
    int prime[200] = {0, 2};//����һ������ 
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
