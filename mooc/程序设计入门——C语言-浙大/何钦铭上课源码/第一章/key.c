/*---------------------------------------------文件key.c------------------------------------------------*/
#include <bios.h>

/*定义有效的键值*/
#define ENTER 0x1c0d
#define UP 0x4800
#define DOWN 0x5000
#define LEFT 0x4b00
#define RIGHT 0x4d00

#define ESC 0x011b
#define SPACE 0x3920

#define LOWERF 0x2166
#define UPPERF 0x2146

#define LOWERA 0x1e61
#define UPPERA 0x1e41

#define LOWERQ 0x1071
#define UPPERQ 0x1051

/*获取按键信息，返回有效的操作值*/
int getKey(void){
  while(1){
    int key=bioskey(0);
    switch(key){
    case ENTER:
    case UP:
    case DOWN:
    case LEFT:
    case RIGHT:
    case ESC:
    case SPACE:
    case LOWERF:
    case UPPERF:
    case LOWERA:
    case UPPERA:
    case LOWERQ:
    case UPPERQ: return key;
    }
  }
}
/*------------------------------------------文件 key.c结束------------------------------------------*/