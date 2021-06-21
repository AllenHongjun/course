/*-------------------------------------------�ļ�main.c----------------------------------------------*/
#include "key.c"
#include "miner.c"

int main(){
  int gameRes; /*��¼��Ϸ�����Ľ��״̬��0��ʾ�˳���Ϸ��-1��Ϸʧ�ܣ� 1Ϊʤ����*/
  initGraph();  /*��ʼ��ͼ����ʾ��ʽ*/
do{
     newGame(); /*��ʼ���µ���Ϸ*/
     gameRes=0;
     /*main loop  dealing with keystroke messages*/
     do{
       int key = getKey();  /*���������Ϣ*/
       if(key == ESC) break;
       switch(key){       /*��������Ч�����Ĵ���*/
       case ENTER: case SPACE: gameRes = openMine(pi,pj);break;
       case UP: moveUp();break;
       case DOWN: moveDown();break;
       case LEFT: moveLeft();break;
       case RIGHT: moveRight();break;
       case LOWERF: case UPPERF: flagBlock(pi,pj);break;
       case LOWERA: case UPPERA: gameRes = autoOpen(pi,pj);break;
       case LOWERQ:case UPPERQ: questBlock(pi,pj);break;
       }
       if(checkWin()) gameRes = 1;
     } while(!gameRes);
  } while (!confirm(gameRes)) ;
  return 0;
}
/*------------------------------------------ �ļ�main.c����------------------------------------------*/