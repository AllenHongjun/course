#include <stdio.h>
int main( )
{ 
    int i, x, n, a[n];

    printf("��������Ԫ�صĸ�����");
    scanf("%d", &n);
    printf("��������%d��Ԫ�أ�",n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf( "x= " );    
    scanf("%d", &x);	
    for(i = 0; i < n; i++)	 
        if(a[i] != x)  break;	
    if(i!=n)
        printf( "û���ҵ���%d��ȵ�Ԫ��!\n", d);
    else
        printf( "��%d��ͬ������Ԫ����a[%d]=%d\n", x, i, a[i]); 

    return 0;
}
