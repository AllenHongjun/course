/*
01-���Ӷ�3 ���ֲ��ң�20 �֣�
����Ҫ��ʵ�ֶ��ֲ����㷨��

�����ӿڶ��壺
Position BinarySearch( List L, ElementType X );
����List�ṹ�������£�

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */

/*L���û������һ�����Ա�����ElementTypeԪ�ؿ���ͨ��>��==��<���бȽϣ�������Ŀ��֤����������ǵ�������ġ�����BinarySearchҪ����X��Data�е�λ�ã��������±꣨ע�⣺Ԫ�ش��±�1��ʼ�洢�����ҵ��򷵻��±꣬���򷵻�һ�������ʧ�ܱ��NotFound��
*/



#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
