/* ����������9-3.cpp  */

/* ���ܣ��ṹ������Ϊ��������������ְ����ʵ������ */

#include <stdio.h>
struct employee
{
	int num;
	char name[20];
	float jbgz,jj,bx,sfgz;
};

//�ṹ�ֲ�����ָ�� Ϊʲô���Դ��뵽������ֱ���޸�ֵ  ���� �Ƿ����޸�֮���ֵ ���� ���� �޸�ֵ ֮�������ṹ ����Ƿ��ز��˵�
float count_sfgz(struct employee m);

int main(void)
{
	int i,n;
	struct employee e;
	
	printf("������ְ������n:");
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%s", &e.num, e.name);
        scanf("%f%f%f", &e.jbgz, &e.jj, &e.bx);
		e.sfgz = count_sfgz(e);
		printf("���:%d ����:%s ʵ������:%.2f\n", e.num, e.name, e.sfgz);
	}
	return 0;
}

//�ṹ���� ��ֵ���� �ṹ��ָ���� ���ݵ�ַ  �൱����Ӧ�ô��ݡ�
float count_sfgz(struct employee m)
{
	return m.jbgz+m.jj-m.bx;
}












