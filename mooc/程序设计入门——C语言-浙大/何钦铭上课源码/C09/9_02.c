/* ����������9-2.cpp  */

/* ���ܣ�����ְ����ʵ������ */

/*
#include<stdio.h>
struct employee{         
    int num;
    char name[20];
    float jbgz, jj, bx, sfgz;
};

int main(void)
{    
    int i, n;
    struct employee e;   

    printf("������ְ������n: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        printf("�������%d��ְ������Ϣ: ", i);
        scanf("%d%s", &e.num, e.name);
        scanf("%f%f%f", &e.jbgz, &e.jj, &e.bx);
        e.sfgz = e.jbgz + e.jj - e.bx;
        printf("���:%d ����:%sʵ������:%.2f\n", e.num, e.name, e.sfgz);
    }

    return 0;
}
*/

#include <stdio.h>
struct employee
{        /*����ṹ���� emploayee*/
	int num;
	char name[20];
	float jbgz, jj, bx ,sfgz;

};

int main(void)
{
	int i,  n;
	struct employee e;  //����ṹ���ͱ��� e
	
	printf("������ְ������n: ");
	scanf("%d",&n);
	for (i = 1; i <= n; i++)
	{
		printf("�������%d��ְ������Ϣ�� ",i);
		scanf("%d%s", &e.num, e.name);
		scanf("%f%f%f", &e.jbgz, &e.jj, &e.bx);
		e.sfgz =  e.jbgz + e.jj - e.bx;
		printf("��ţ�%d ������%s ʵ������ :%.2f\n", e.num, e.name, e.sfgz);
	}
	return 0;
}
