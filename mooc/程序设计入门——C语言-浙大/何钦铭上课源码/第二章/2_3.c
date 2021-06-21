/*-------Àý³Ì2-3-------*/
#include <stdio.h>
#include <dos.h>
int main()
{
  char far *p;
  printf("\n");
  p="This is a program to illustrate how to use DOS interrupt 09H.$";
  _DS=FP_SEG(p);
  _DX=FP_OFF(p);
  _AH=9;
  geninterrupt(0x21);
}
/*-------Àý³Ì2-3½áÊø-------*/