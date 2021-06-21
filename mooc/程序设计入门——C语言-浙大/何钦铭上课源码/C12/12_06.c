/*【例12-6】从键盘输入两个学生数据，写入一个文件中， 再读出这两个学生的数据显示在屏幕上。*/

#include <stdio.h>
struct stu
{
    char name[10];
    int num;
    int age;
    char addr[15];
} boya[2], boyb[2], *pp, *qq;
int main(void)
{
    FILE *fp;
    int i;

    pp = boya;
    qq = boyb;
    if ((fp = fopen("stu_list.txt", "wb+")) == NULL)
    {
        printf("Cannot open file strike any key exit!");
        getchar();
        exit(1);
    }
    printf("\ninput data\n");
    for (i = 0; i < 2; i++, pp++)
        scanf("%s%d%d%s", pp->name, &pp->num, &32pp->age, pp->addr);
    pp = boya;
    fwrite(pp, sizeof(struct stu), 2, fp);
    rewind(fp);
    fread(qq, sizeof(struct stu), 2, fp);
    printf("\n\nname\tnumber age addr\n");
    for (i = 0; i < 2; i++, qq++)
        printf("%s\t%5d%7d\t%s\n", qq->name, qq->num, qq->age, qq->addr);
    fclose(fp);

    return 0;
}
