/*-------Àý³Ì2-2 -------*/
#include <stdio.h>
#include <dos.h>

int delete_file(char near *filename)
{
  union REGS regs;
  int ret;
  regs.h.ah=0x41;
  regs.x.dx=(unsigned)filename;
  ret=intdos(&regs,&regs);
  return(regs.x.cflag?ret:0);
}

int main(void)	
{
  char filename[80];
  int err;
  printf("Enter filename: ");
  gets(filename);
  err=delete_file(filename);
  if(!err)
    printf("Able to delete %s\n",filename);
  else
    printf("Not able to delete,this file do not exist\n");
  return 0;
}
/*-------Àý³Ì2-2½áÊø-------*/