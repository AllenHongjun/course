/*����5-5����100���ڵ�ȫ��������ÿ�����10������������ֻ�ܱ�1��������������������1����������2��������Ҫ����͵��ú���prime(m)�ж�m�Ƿ�Ϊ��������mΪ����ʱ����1�����򷵻�0��*/

/* ʹ�ú�����100���ڵ�ȫ������ */

#include <stdio.h>
#include <math.h>
int main(void)
{
    int count,m;
    int prime(int m);
    count = 0;

    for(m = 2;m <= 5000; m++){
        if (prime(m))
        {
            printf("%6d",m);
            count++;
            if (count%10 ==0)
            {
                printf("\n");
            }
        }
    }
    printf("\n");
}

int prime(int m)
{
    int i,n;
    if(m ==1) return 0;
    n = sqrt(m);
    for(i =2; i<= n ;i++){
        //������i�� n���е����� �����һ���ܱ�m���� ��ôm�Ͳ������� �����������
        if(m % i == 0){
            return 0;
        }
    }
    return 1;
}





