#include <stdio.h>
int main (void)
{
    struct student{
        int number;
	char name[20];
	int score[3];
	int sum;
    };						
    int i, j, k, n, max=0;

    printf("����n��");
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        printf("�����%d��ѧ����ѧ�š�������3�ųɼ�:");
        scanf("%d%s", &student[i].number, &student[i].name);  
        for(j = 0; j < 3; j++){
	    scanf("%d", &student[i].score[j]);  
	    student[i].sum += student[i].score[j];  
	}
   }
   max = student[0].sum;
   for(i = 0; i < n; i++)
       if(max < student[i].sum) { 
          max = student[i].sum; 
	  k = i; 
       }
   printf("�ܷ���ߵ�ѧ����: %s��%d��\n", student[k].name, student[k].sum);

   return 0;
}
