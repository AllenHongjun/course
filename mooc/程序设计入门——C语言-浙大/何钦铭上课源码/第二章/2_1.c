/*-------����2-1-------*/
#include <stdio.h>
#include <dos.h>
#include <conio.h>
main()
{
  char c[200];
  int x;
  void cursorgo(unsigned char,unsigned char);
  
  clrscr();         /*����*/
  cursorgo(5,5);    /*�����*/
  printf("Name:");
  cursorgo(5,25);
  printf("Age:");
  cursorgo(5,35);
  printf("Sex:");
  cursorgo(7,5);
  printf("Description:\n");
  cursorgo(5,10);   /*����*/
  gets(c);
  cursorgo(5,29);
  scanf("%s%*c",c);
  cursorgo(5,39);
  scanf("%s%*c",c);
  cursorgo(8,5);
  gets(c);
}
void cursorgo(unsigned char row,unsigned char column)
{
  union REGS inreg,outreg;
  inreg.h.ah=2;    /*���ù��λ��*/
  inreg.h.bh=0;    /*ҳ��*/
  inreg.h.dh=row;  /*�к�*/
  inreg.h.dl=column;/*�к�*/
  int86(0x10,&inreg,&outreg);
}
/*-------����2-1����-------*/