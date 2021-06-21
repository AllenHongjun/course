//BeatPlane
#include<windows.h>
#include"resource.h"
#include"BEATPLANE.h"

int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
                   PSTR szCmdLine,
				   int iCmdShow)
{
	static	TCHAR	szAppName[] = TEXT("BeatPlane");
	HWND			hwnd;
	MSG				msg;
	WNDCLASS		wndclass;
	int				cxScreen, cyScreen;
	
	wndclass.style			= CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc	= WndProc;
	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
	wndclass.hInstance		= hInstance;
	wndclass.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP));
	wndclass.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground	= NULL;
	wndclass.lpszMenuName	= NULL;
	wndclass.lpszClassName	= szAppName;
	
	if(!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"),
			szAppName, MB_ICONERROR);
		return 0;
	}
	
	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);
	hwnd = CreateWindowA(szAppName,
						NULL,
						WS_POPUPWINDOW & (~WS_BORDER),
						(cxScreen - WNDWIDTH) / 2,
						(cyScreen - WNDHEIGHT + 100) / 2,
						WNDWIDTH,
						WNDHEIGHT,
						NULL,
						NULL,
						hInstance,
						NULL);

	ShowWindow(hwnd, iCmdShow);

	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return msg.wParam;
}

//���ָ������������ٶȵķɻ�
VOID AddPlane(int add, int speed)
{
	int			i, index, cur = iCurLen; 
	BITMAP		bmp;

	srand(GetTickCount());

	if(add+cur > MAX)
		iCurLen = MAX-1;
	else
		iCurLen += add;

	//��ӷɻ�
	for(i=cur; i<iCurLen; i++)
	{
		index = rand()%3;
		
		//��֤ÿһ��ֻ��һ����ɻ�
		while(index==2 && isBigAdd)
		{
			index = rand()%3;
		}

		if(!isBigAdd && index==2)
			isBigAdd = TRUE;

		GetObject(hBmp[index+1], sizeof(BITMAP), &bmp);

		pPlaneArr[i].hBmp	= hBmp[index+1];
		pPlaneArr[i].moveSpeed = speed - index?(speed - index):1;
		pPlaneArr[i].type	= index+2;
		
		pPlaneArr[i].size.cx= bmp.bmWidth;
		pPlaneArr[i].size.cy= bmp.bmHeight / pPlaneArr[i].type;

		pPlaneArr[i].pos.x  = rand()%(WNDWIDTH - pPlaneArr[i].size.cx);
		pPlaneArr[i].pos.y	= - pPlaneArr[i].size.cy - rand()%(pPlaneArr[i].size.cy * (4 - index));

		if(score>=GRADE && score<GRADE*2)
		{
			grade = 1;
		}
		else if(score>=GRADE*2 && score<GRADE*4)
		{
			grade = 2;
		}
		else if(score>=GRADE*4 && score<GRADE*5)
		{
			grade = 3;
		}
		else
		{
			grade = 4;
		}
		pPlaneArr[i].moveSpeed += grade;
	}

	GetObject(pauseBmp.hBmp, sizeof(BITMAP), &bmp);
	pauseBmp.size.cx	= bmp.bmWidth;
	pauseBmp.size.cy = bmp.bmHeight / 2;
}

//��˫���弼�����ɻ�λͼ
VOID StickPlanes(HDC hdc)
{
	TCHAR		szScore[MAX+3];
	HDC		hdcBmp, hdcBuffer;
	HBITMAP	cptBmp;
	int		i, len;

	cptBmp = CreateCompatibleBitmap(hdc, WNDWIDTH, WNDHEIGHT);

	hdcBmp = CreateCompatibleDC(hdc);
	hdcBuffer = CreateCompatibleDC(hdc);
	SelectObject(hdcBuffer, cptBmp);
	SelectObject(hdcBmp, hBmp[0]);

	//������
	BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT,
		   hdcBmp, 0, 0, SRCCOPY);

	//���ɻ�
	for(i=0; i<iCurLen; i++)
	{
		SelectObject(hdcBmp, pPlaneArr[i].hBmp);
		
		TransparentBlt(
			hdcBuffer, pPlaneArr[i].pos.x, pPlaneArr[i].pos.y,
			pPlaneArr[i].size.cx, pPlaneArr[i].size.cy,
			hdcBmp, 0, 0, pPlaneArr[i].size.cx, pPlaneArr[i].size.cy,
			RGB(255, 255, 255)
		);				   
	}

	//����ͣ�����λͼ
	SelectObject(hdcBmp, pauseBmp.hBmp);
	TransparentBlt(hdcBuffer, 0, 0, pauseBmp.size.cx, pauseBmp.size.cy,
		hdcBmp, 0, pauseBmp.size.cy * pauseBmp.isPaused, 
		pauseBmp.size.cx, pauseBmp.size.cy, RGB(255, 255, 255));

	//��ʾ����
	SetTextColor(hdcBuffer, RGB(185, 122, 87));
	SetBkMode(hdcBuffer, TRANSPARENT);
	len = wsprintf(szScore, "����:%d", score);
	TextOut(hdcBuffer, 30, 5, szScore, len);


	//������е���Ϣ������Ļ��
	BitBlt(hdc, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBuffer, 0, 0, SRCCOPY);

	//�мǻ�����Դ��ռ���ڴ�
	DeleteObject(cptBmp);
	DeleteDC(hdcBuffer);
	DeleteDC(hdcBmp);
}

//�жϴ�ɻ��Ƿ�ɹ�
BOOL Beat(HWND hwnd, POINT ptMouse)
{
	RECT	rBmp;
	int		i, Len = iCurLen;

	for(i=0; i<Len; i++)
	{
		rBmp.left	= pPlaneArr[i].pos.x;
		rBmp.top	= pPlaneArr[i].pos.y;
		rBmp.right	= rBmp.left + pPlaneArr[i].size.cx;
		rBmp.bottom	= rBmp.top + pPlaneArr[i].size.cy;

		if(PtInRect(&rBmp, ptMouse))
		{
			Boost(hwnd, pPlaneArr + i);

			DeletePlane(i);

			//ɾ���� ��ǰ�ɻ���ҲӦ�ü�1
			iCurLen--;
			return TRUE;
		}
	}

	return FALSE;
}

//ʵ�ֱ�ըЧ��
VOID Boost(HWND hwnd, PPlane bstPlane)
{
	HDC		hdc, hdcMem;

	hdc = GetDC(hwnd);
	hdcMem = CreateCompatibleDC(hdc);

	switch(bstPlane->type)
	{
	case SMALL:
		SelectObject(hdcMem, hBmp[1]);
		score += 1000;
		break;

	case MIDDLE:
		SelectObject(hdcMem, hBmp[2]);
		score += 6000;
		break;

	case BIG:
		SelectObject(hdcMem, hBmp[3]);
		score += 10000;
		isBigAdd = FALSE;
		break;
	}

	TransparentBlt(hdc, bstPlane->pos.x, bstPlane->pos.y-1, 
		bstPlane->size.cx, bstPlane->size.cy,
		hdcMem, 0, (bstPlane->type - 1) * bstPlane->size.cy,
		bstPlane->size.cx, bstPlane->size.cy,
		RGB(255, 255, 255));

	Sleep(30);

	DeleteDC(hdcMem);
	ReleaseDC(hwnd, hdc);
}

//ɾ��ָ�������ķɻ�
VOID DeletePlane(int index)
{
	int j;

	for(j=index; j<iCurLen-1; j++)
		pPlaneArr[j] = pPlaneArr[j+1];
}

//�ж��Ƿ�������ͣ
BOOL Paused(POINT ptMouse)
{
	RECT rPause;

	rPause.left		= 0;
	rPause.top		= 0;
	rPause.right	= pauseBmp.size.cx;
	rPause.bottom	= pauseBmp.size.cy;

	return PtInRect(&rPause, ptMouse);
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	POINT		ptMouse;//�����������
	HDC			hdc;
	PAINTSTRUCT	ps;
	int			i;
	
	switch(message)
	{
	case WM_CREATE:
		//һ��ʼ��һ���ж�(�����Ի����)
		if(IDNO == MessageBox(hwnd, TEXT("\t׼����ʼ��^_^"),
			TEXT("��ɻ�"), MB_YESNO))
		{
			SendMessage(hwnd, WM_DESTROY, 0, 0);
		}

		//���������λͼ
		for(i=0; i<4; i++)
		{
			hBmp[i] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, 
								MAKEINTRESOURCE(iBmpNames[i]));
		}

		pauseBmp.hBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, 
								MAKEINTRESOURCE(IDB_PLAY));
		pauseBmp.isPaused = FALSE;

		SendMessage(hwnd, WM_START, 0, 0);
	  	return 0;

	//��ʼ�����¿�ʼ��Ϸ����Ϣ
	case WM_START:
		iCurLen = 0;
		score = 0;
		AddPlane(10, 2);
		SetTimer(hwnd, TIMER, 50, NULL);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		StickPlanes(hdc);

		EndPaint(hwnd, &ps);
		return 0;

	//��ʱ����Ϣ(���Ʒɻ�������)
	case WM_TIMER:
		for(i=0; i<iCurLen; i++)
		{
			pPlaneArr[i].pos.y += pPlaneArr[i].moveSpeed;

			if(pPlaneArr[i].pos.y > WNDHEIGHT)
			{
				KillTimer(hwnd, TIMER);
				
				if(IDYES == MessageBox(hwnd, 
					TEXT("\t��Ϸ����>.<\n\t��������һ����?"), 
					TEXT("��ɻ�"), MB_YESNO))
				{
					SendMessage(hwnd, WM_START, 0, 0);
				}

				else
				{
					SendMessage(hwnd, WM_CLOSE, 0, 0);
				}
			}
		}
		InvalidateRect(hwnd, NULL, FALSE);
		return 0;

	//ͨ��������������ɻ�
	case WM_LBUTTONDOWN:
		ptMouse.x = LOWORD(lParam);
		ptMouse.y = HIWORD(lParam);

		//�������˼�������ͣͼ��
		if(Paused(ptMouse))
		{
			if(!pauseBmp.isPaused)
			{
				KillTimer(hwnd, TIMER);
				pauseBmp.isPaused = TRUE;
			}
			else
			{
				SetTimer(hwnd, TIMER, 50, NULL);
				pauseBmp.isPaused = FALSE;
			}

			InvalidateRect(hwnd, NULL, FALSE);
		}

		//���û�����ͣ���Ҵ����˷ɻ�
		else if(!pauseBmp.isPaused && Beat(hwnd, ptMouse))
		{
			AddPlane(1, 3);
		}

		return 0;

	case WM_DESTROY:
		for(i=0; i<4; i++)
			DeleteObject(hBmp[i]);

		KillTimer(hwnd, TIMER);
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}