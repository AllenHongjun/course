/********************************************************************************
*File name:SnakeGame2.0.c                                                       *
*Author:����                                                                    *
*Version:2.0                                                                    *
*Date:2018.04.17                                                                *
*Debug Environment:Visual Studio 2017                                           *
*Description:̰������ϷԴ���루C���ԣ�������ڵ�һ�汾�Ľ���draw����������win32 *
*�ľ�����Ľ���ʾ�������⡣��������ͣ���ܡ�д��һ����AI������Ϸ               *
*********************************************************************************/
#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<math.h>
#include<conio.h>

#define SIZE 19 //�����ͼ��С
#define MAX_LENGTH 90 //�����ߵ���󳤶�

typedef struct point //��ͼ�ϵĵ�Ľڵ�
{
	int r;
	int c;
} point;
HANDLE stdOutput; //����windows��׼������

void init(int * length, point * foodAt, int * dir, point body[], char map[][SIZE]); //��ʼ��
int getDir(int dir); //��ȡ�ߵ��н�����
int getAIDir(int dir, int length, point body[], point foodAt); //��ȡAI�жϵó����н�����
int moveable(point moveTo, int length, point body[]); 
int move(point foodAt, int dir, int length, point body[]); //�ߵ��˶�
void draw(int length, point foodAt, point body[], char map[][SIZE]); //��ͼ
void food(point * foodAt, point body[], int length, char map[][SIZE]); //����ʳ��

int main()
{
	char map[SIZE][SIZE]; //�����ͼ
	point body[MAX_LENGTH], foodAt; //�����������ʳ������ڵ㣨body����ĵ�һ��ֵΪ��ͷ��
	int length; //�ߵ�ʵ�ʳ���
	int dir; //�н�����
	int rate = 1; //�н�����
	int result; //�������˶��Ľ�����������������÷֡������ޡ�
	init(&length, &foodAt, &dir, body, map); //��ʼ��

	while (1)
	{
		Sleep(50 / rate);
		//dir = getDir(dir); //��ȡ�ߵ��н�����
		dir = getAIDir(dir, length, body, foodAt); //��ȡAI�жϵó����н�����
		result = move(foodAt, dir, length, body); //�ߵ��˶�
		if (result == 1) //����Ե�ʳ��
		{
			length++;
			rate = length / 3;
			if (length == MAX_LENGTH)
			{
				printf("����ͨ�أ�");
				break;
			}
			food(&foodAt, body, length, map); //����ʳ��
		}
		draw(length, foodAt, body, map); //��ͼ
		if (result == -1) //�������
		{
			break;
		}

	}
	Sleep(500);
	printf("  ʧ�ܣ��˴ε÷�Ϊ%d                          ", (length - 3) * 100);
	system("pause");
}
void init(int * length, point * foodAt, int * dir, point body[], char map[][SIZE]) //��ʼ��
{
	memset(map, '*', SIZE * SIZE); //��ʼ����ͼ
	body[0].r = 3, body[0].c = 2; //��ʼ���ߵ�����
	body[1].r = 2, body[1].c = 2;
	body[2].r = 1, body[2].c = 2;
	*length = 3; //��ʼ����Ϊ3
	*dir = 2; //��ʼ��������
	food(foodAt, body, *length, map); //����ʳ��
	draw(*length, *foodAt, body, map); //��ͼ
	printf(" �����������ʼ����ASDW���Ʒ���ESC��ͣ\n");
	_getch();
	srand((unsigned)time(NULL)); //������������ӣ�����
	stdOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(stdOutput, &cci);
	COORD coord = { 0, SIZE * 2 + 3 };
}
int getDir(int dir) //��ȡ�ߵ��н����򣬹涨����ֵ0�������ϣ�1�������ң�2�������£�3��������
{
	char key;
	int newDir = dir;
	if (_kbhit())
	{
		key = _getch();
		switch (key)
		{
		case 'A': case 'a': newDir = 3; break;
		case 'S': case 's': newDir = 2; break;
		case 'D': case 'd': newDir = 1; break;
		case 'W': case 'w': newDir = 0; break;
		case 27: _getch(); break;
		}
	}
	if (newDir - dir == 2 || newDir - dir == -2) //�߲��ܷ���
	{
		newDir = dir;
	}
	return newDir;
}
int getAIDir(int dir, int length, point body[], point foodAt) //��ȡAI�жϵó����н�����
{
	int i, newDir = 0, distanceToFood;
	point moveTo;
	int dir_weight[4]; //�ϡ��ҡ��¡����ĸ������Ȩֵ
	distanceToFood = abs(body[0].r - foodAt.r) + abs(body[0].c - foodAt.c);
	for (i = 0; i < 4; i++)
	{
		if (abs(dir - i == 2)) //�߲��ܷ���
		{
			dir_weight[i] = -1; //Ȩֵȡ��С
		}
		else
		{
			switch (i)
			{
			case 0: moveTo.r = body[0].r - 1, moveTo.c = body[0].c; break;
			case 1: moveTo.r = body[0].r, moveTo.c = body[0].c + 1; break;
			case 2: moveTo.r = body[0].r + 1, moveTo.c = body[0].c; break;
			case 3: moveTo.r = body[0].r, moveTo.c = body[0].c - 1; break;
			}
			if (!moveable(moveTo, length, body)) //����ƶ�������
			{
				dir_weight[i] = 0; //Ȩֵȡ0
			}
			else
			{
				if (distanceToFood > abs(moveTo.r - foodAt.r) + abs(moveTo.c - foodAt.c)) //����ƶ���ʳ��ľ������
				{
					dir_weight[i] = 2; //Ȩֵȡ2
				}
				else
				{
					dir_weight[i] = 1; //Ȩֵȡ1
				}
			}
		}
	}

	for (i = 1; i < 4; i++) //ȡȨֵ���ķ���
	{
		if (dir_weight[i] > dir_weight[newDir])
		{
			newDir = i;
		}
	}
	return newDir;
}
int moveable(point moveTo, int length, point body[]) //�ж��Ƿ�����ƶ���moveTo�㣬��1������0
{
	int i;
	for (i = 0; i < length - 1; i++)
	{
		if (moveTo.r == body[i].r && moveTo.c == body[i].c)
		{
			return 0;
		}
	}
	if (moveTo.r < 0 || moveTo.r >= SIZE || moveTo.c < 0 || moveTo.c >= SIZE) //��������߽�
	{
		return 0;
	}
	return 1;
}
int move(point foodAt, int dir, int length, point body[]) //�ߵ��˶����涨����ֵ-1����������0����û�гԵ�ʳ�1����Ե�ʳ��
{
	int i, flag = 0;
	point head = body[0];
	switch (dir)
	{
	case 0: head.r -= 1; break;
	case 1: head.c += 1; break;
	case 2: head.r += 1; break;
	case 3: head.c -= 1; break;
	}
	if (head.r < 0 || head.r >= SIZE || head.c < 0 || head.c >= SIZE) //����������
	{
		return -1;
	}
	for (i = 0; i < length - 1; i++)
	{
		if (head.r == body[i].r && head.c == body[i].c) //ҧ�����Լ�����
		{
			return -1;
		}
	}
	if (head.r == foodAt.r && head.c == foodAt.c) //�Ե���ʳ��
	{
		length++;
		flag = 1; //���һ�£�������·���ֵΪ1
	}
	for (i = length - 1; i > 0; i--) //�ƶ��ߵ�λ��
	{
		body[i] = body[i - 1];
	}
	body[0] = head; //��һ��ͷ
	if (flag == 1)
	{
		return 1;
	}
	return 0;
}
void draw(int length, point foodAt, point body[], char map[][SIZE]) //��ͼ
{

	static char bitmap[SIZE + 2][SIZE + 2]; //����һ�����飬���ڰѵ�ͼ�������߽硢�ߡ�ʳ�ﶼ����ȥ
	int i, j;
	for (i = 0; i < SIZE; i++) //����
	{
		for (j = 0; j < SIZE; j++)
		{
			bitmap[i + 1][j + 1] = map[i][j];
		}
	}
	//�߿�
	bitmap[0][0] = '0', bitmap[0][SIZE + 1] = '1';
	bitmap[SIZE + 1][0] = '2', bitmap[SIZE + 1][SIZE + 1] = '3';
	for (i = 0; i < SIZE; i++)
	{
		bitmap[0][i + 1] = '4', bitmap[SIZE + 1][i + 1] = '4';
		bitmap[i + 1][0] = '5', bitmap[i + 1][SIZE + 1] = '5';
	}
	bitmap[foodAt.r + 1][foodAt.c + 1] = 'f'; //ʳ��
	bitmap[body[0].r + 1][body[0].c + 1] = 'h'; //��ͷ
	for (i = 1; i < length; i++) //����
	{
		bitmap[body[i].r + 1][body[i].c + 1] = 'b';
	}

	COORD coord = { 0, 0 }; //����0��0
	SetConsoleCursorPosition(stdOutput, coord); //�ѹ�����õ�0��0λ��
	for (i = 0; i < SIZE + 2; i++)
	{
		for (j = 0; j < SIZE + 2; j++)
		{
			switch (bitmap[i][j])
			{
			case 'f': printf("��"); break;
			case 'b': printf("��"); break;
			case 'h': printf("��"); break;
			case '0': printf("��"); break;
			case '1': printf("����"); break;
			case '2': printf("��"); break;
			case '3': printf("����"); break;
			case '4': printf(" ��"); break;
			case '5': printf("�� "); break;
			default: printf("��");
			}
		}
		printf("\n");
	}
}
void food(point * foodAt, point body[], int length, char map[][SIZE]) //����ʳ��
{
	int i;
	while (1)
	{
		foodAt->r = rand() % SIZE, foodAt->c = rand() % SIZE; //�������ʳ��λ��
		for (i = 0; i < length; i++)
		{
			if (foodAt->r == body[i].r && foodAt->c == body[i].c) //�����λ�����ߵ�������
			{
				goto retry;
			}
		}
		break;
	retry:;
	}
}