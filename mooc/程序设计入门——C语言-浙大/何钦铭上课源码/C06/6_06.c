/*����6-6���߼����ʽ�����á�*/

/* �߼�����ʾ�� */

#include <stdio.h>
int main(void){

    char ch = 'w';
    int a = 2,b = 0,c =0;  //�Ƚ׶�C���Ե���Ȥ���Ǿ�����Щ�������ַ����� ������Ȥ���ڷǳ����Ͻ�
    
    float x = 3.0;

    printf("%d ",a && b); // 0
    printf("%d ",a || b && c); // 0  1/*exp1 || exp2����exp1������ֵΪ1��STOP*/
    printf("%d ",!a && b);// 0
    printf("%d ",a||3 + 10&&2); //2   1
    printf("%d ",!(x == 2)); //1
    printf("%d ",!x == 2); //0
    printf("%d\n", ch || b);//1
    return 0;
}


// #include <stdio.h> 
// int main(void)
// {
//     char ch = 'w';
//     int a = 2, b = 0, c = 0;
//     float x = 3.0; 

//     printf("%d ", a && b);
//     printf("%d ", a || b && c);
//     printf("%d ", !a && b);
//     printf("%d ", a||3+10&&2);
//     printf("%d ", !(x == 2));
//     printf("%d ", !x == 2);
//     printf("%d\n ", ch || b);

//     return 0;
// }
