#ifndef BEATPLANE_H

#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "Winmm.lib")

#define WM_START	(WM_USER+100)

#define TIMER		100
#define WNDWIDTH	380
#define WNDHEIGHT	550
#define SMALL		2
#define MIDDLE		3
#define BIG			4
#define GRADE		200000
#define MAX			10//窗口中一次显示最多的飞机数

//飞机结构体
typedef struct
{
	HBITMAP	hBmp;
	POINT	pos;
	SIZE	size;
	int		moveSpeed;
	int		type;
}Plane, *PPlane;

//play结构体
typedef struct
{
	HBITMAP	hBmp;
	SIZE	size;
	BOOL	isPaused;
}Pause;

int		iBmpNames[] = {IDB_BK, IDB_SMALL, IDB_MIDDLE, IDB_BIG};
Plane	pPlaneArr[MAX];
Pause	pauseBmp;
HBITMAP	hBmp[4];
int		iCurLen;//当前飞机数
int		score;//标记分数
int		grade;//等级(用于变速)
BOOL	isBigAdd=FALSE;//判断打飞机是否已经添加

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
VOID StickPlanes(HDC);//用双缓冲贴飞机位图
VOID AddPlane(int, int);//添加飞机
BOOL Beat(HWND, POINT);//判断打飞机是否成功
VOID Boost(HWND, PPlane);//实现爆炸效果
VOID DeletePlane(int);//删除指定索引的飞机
BOOL Paused(POINT);//判断是否点击了暂停

#endif