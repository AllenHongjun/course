/*-------------------------------------------文件main.c----------------------------------------------*/
#include "key.c"
#include "miner.c"

int main(){
  int gameRes; /*记录游戏结束的结果状态：0表示退出游戏；-1游戏失败； 1为胜利。*/
  initGraph();  /*初始化图形显示方式*/
do{
     newGame(); /*初始化新的游戏*/
     gameRes=0;
     /*main loop  dealing with keystroke messages*/
     do{
       int key = getKey();  /*读入操作信息*/
       if(key == ESC) break;
       switch(key){       /*对其他有效操作的处理*/
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
/*------------------------------------------ 文件main.c结束------------------------------------------*/