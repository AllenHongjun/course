/* ����������9-4.cpp  */

/* ���ܣ����ɼ��Ӹߵ������ѧ����Ϣ */
#include <stdio.h>
struct student{
    int  num;
    char name[20];//�ַ����� char����ֻ�ܴ��һ���ַ����𣿣� C���Ե��ַ����� ��������ַ����ġ���Ĭ�ϵĺ������һ��/0
    int  score;
}; 
struct student stud[10];	/* �����¼10��ѧ����Ϣ�Ľṹ���� */

int main(void)
{
    int i, j, index, sum = 0;
    struct student temp;	/* �������� */

    /* ����10��ѧ���ļ�¼�����ۼӳɼ� */
    printf("\nInput the student's number, name and score: \n");
    for(i = 0; i < 10; i++){			
        printf("No %d: ", i+1);		/* ��ʾ�����i��ͬѧ����Ϣ  */
        scanf("%d%s%d", &stud[i].num, stud[i].name, &stud[i].score);
        sum = sum + stud[i].score;
    }
    /* ���շ����ӵ͵�������ʹ��ѡ������ */
    for( i = 0; i < 9; ++i ){		/*  �ⲿѭ��  */
        index =i;
        for (j = i+1; j <10; j++ )	/*  �ڲ�ѭ��  */
            if (stud[j].score < stud[index].score)   /* �Ƚϳɼ��Ĵ�С */
                index = j;
        temp = stud[index];		/* ��������Ԫ�� */
        stud[index] = stud[i];
        stud[i] = temp;
    }
    /*  ����ɼ� */
    printf("The average: %d\n", sum/10 );/* ���ƽ���� */
    printf("The student score:\n"); 
    for (i = 9; i >= 0; i-- ) 
        printf("%d %s %d\n", stud[i].num, stud[i].name, stud[i].score);

    return 0;
}
