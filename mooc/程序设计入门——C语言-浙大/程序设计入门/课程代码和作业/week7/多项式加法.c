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
    //判断最大幂 
    int maxpower = 0;
    int j;
    for ( j = N; j > 0; j-- ) {
        if (A[j] != 0 ) {
            maxpower = j;
            break;
        }
    }
    //分只有0次幂和有非0次幂两种情况 
    if (maxpower == 0) {
        printf("%d", A[0]); //如果只有0次幂，直接输出 
    } else {
    	int i;
        for (  i = maxpower; i > -1; i--) {
            //非0次幂分幂大于1，幂等于1，幂等于0三种情况，每种情况中又分系数绝对值为1和不为1两种情况。 
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
            //为方便理解，上面用的全部是绝对值，故需要添加运算符号。通过判断下一个非0系数添加符号。 
            if ( i > 0){
                if ( A[i-1] > 0 ) {
                    printf("+");
                } else if ( A[i-1] < 0 ) {
                    printf("-");    //负数可不用绝对值，不额外输出负号，但为代码可读性，符号统一输出。 
                }
            }
        }
    }
    
    return 0;
}


