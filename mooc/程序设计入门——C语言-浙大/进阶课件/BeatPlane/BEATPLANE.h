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
#define MAX			10//������һ����ʾ���ķɻ���

//�ɻ��ṹ��
typedef struct
{
	HBITMAP	hBmp;
	POINT	pos;
	SIZE	size;
	int		moveSpeed;
	int		type;
}Plane, *PPlane;

//play�ṹ��
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
int		iCurLen;//��ǰ�ɻ���
int		score;//��Ƿ���
int		grade;//�ȼ�(���ڱ���)
BOOL	isBigAdd=FALSE;//�жϴ�ɻ��Ƿ��Ѿ����

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
VOID StickPlanes(HDC);//��˫�������ɻ�λͼ
VOID AddPlane(int, int);//��ӷɻ�
BOOL Beat(HWND, POINT);//�жϴ�ɻ��Ƿ�ɹ�
VOID Boost(HWND, PPlane);//ʵ�ֱ�ըЧ��
VOID DeletePlane(int);//ɾ��ָ�������ķɻ�
BOOL Paused(POINT);//�ж��Ƿ�������ͣ

#endif