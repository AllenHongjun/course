#include<stdio.h>
#include<math.h>

int main() {
    const int N = 101;
    int A[N];
    int i;
    for ( i = 0; i < N; i++) {
        A[i] = 0;
    }
        
    int endtag = 0;
    int n, a;
    while ( endtag < 2 ) {
        scanf("%d %d", &n, &a);
        
        if ( n == 0 ) {
            endtag ++;
        }
        
        if ( A[n] != 0 ) {
            A[n] += a;
        } else {
            A[n] = a;
        }
    }
    //�ж������ 
    int maxpower = 0;
    int j;
    for ( j = N; j > 0; j-- ) {
        if (A[j] != 0 ) {
            maxpower = j;
            break;
        }
    }
    //��ֻ��0���ݺ��з�0����������� 
    if (maxpower == 0) {
        printf("%d", A[0]); //���ֻ��0���ݣ�ֱ����� 
    } else {
    	int i;
        for (  i = maxpower; i > -1; i--) {
            //��0���ݷ��ݴ���1���ݵ���1���ݵ���0���������ÿ��������ַ�ϵ������ֵΪ1�Ͳ�Ϊ1��������� 
            if ( i > 1) {           
                if ( abs(A[i]) == 1 ) {
                    printf("x%d", i);
                } else if ( abs(A[i]) > 1 ) {
                    printf("%dx%d", abs(A[i]), i);
                }
            } else if (i == 1 ) {
                if ( abs(A[i]) == 1 ) {
                    printf("x");
                } else if ( abs(A[i]) > 1) {
                    printf("%dx", abs(A[i]));
                }
            } else {
                if ( A[i] != 0 ) {
                    printf("%d", abs(A[i]));
                }
            }
            //Ϊ������⣬�����õ�ȫ���Ǿ���ֵ������Ҫ���������š�ͨ���ж���һ����0ϵ����ӷ��š� 
            if ( i > 0){
                if ( A[i-1] > 0 ) {
                    printf("+");
                } else if ( A[i-1] < 0 ) {
                    printf("-");    //�����ɲ��þ���ֵ��������������ţ���Ϊ����ɶ��ԣ�����ͳһ����� 
                }
            }
        }
    }
    
    return 0;
}


