/********************************************************************************
*File name:MineSweeper1.0.c                                                     *
*Author:����                                                                    *
*Version:1.0                                                                    *
*Date:2018.04.20                                                                *
*Debug Environment:Visual Studio 2017                                           *
*Description:ɨ��С��Ϸ��ֻ����򵥹��ܵĵ�һ�汾                               *
*********************************************************************************/
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#define SIZE 15

typedef struct point //���ڼ�¼��ͼ�ϵ�ĳ����
{
	int r; //��
	int c; //��
} point;
HANDLE stdOutput; //������׼������

void init(char map[][SIZE], point * cursor, int * mineNum); //��ʼ��
void draw(char map[][SIZE], point cursor); //��ͼ
int process(int command, point * cursor, int * remain, char map[][SIZE]); //���������ָ�
//����ֵ-1������Ϸʧ�ܣ�1������Ϸʤ��
int getMineNum(point center, char map[][SIZE]);

int main()
{
	char map[SIZE][SIZE]; //�����ͼ����-1��ʾ��ȫ����-2��ʾ������-3��ʾ����ǵİ�ȫ����
	//-4��ʾ����ǵ�����, 0-8����ʾ�Ѿ�ɨ���İ�ȫ�������ִ�����Χ��������9������ʾ��������
	point cursor; //�������λ�ã���Ϸ��꣬��ϵͳ��꣩
	int command, result, remain; //remain����ʣ����Ҫɨ��������
	init(map, &cursor, &remain); //��ʼ����ͼ�����λ�ú��׵�����
	while (1)
	{
		if (_kbhit()) //����ָ������ʱ
		{
			command = _getch(); //���ָ��
			result = process(command, &cursor, &remain, map); //����ָ�������Ϸ���
			draw(map, cursor); //��ͼ
			if (result == 1)
			{
				printf("��Ӯ��");
				break;
			}
			else if (result == -1)
			{
				printf("������");
				break;
			}
		}
	}
	system("pause");
}

void init(char map[][SIZE], point * cursor, int * remain) //��ʼ��
{
	int difficulty = 3, i, j; //�Ѷ������������ɵ������Ͱ�ȫ������
	stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cci; //����ϵͳ���
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(stdOutput, &cci);

	srand((unsigned)(time(NULL))); //�������������
	*remain = 0;
	cursor->r = SIZE / 2, cursor->c = SIZE / 2; //�ѹ����Ϊ��ͼ�м�
	for (i = 0; i < SIZE; i++) //Ϊ��ͼ��ʼ��
	{
		for (j = 0; j < SIZE; j++)
		{
			if (rand() % 10 < difficulty) //���õ���Ϊ����
			{
				map[i][j] = -2; 
			}
			else //���õ���Ϊ��ȫ��
			{
				map[i][j] = -1;
				(*remain)++;
			}
		}
	}
	draw(map, *cursor);
}
void draw(char map[][SIZE], point cursor)
{
	int i, j, k;
	COORD coord = { 0, 0 }; //����
	SetConsoleCursorPosition(stdOutput, coord); //�趨�������
	printf("  ���¿ո��ǣ��������Aȷ��\n        ASDW���ƹ���ƶ�\n");
	for (i = 0; i < SIZE; i++)
	{
		if (i == 0) //�����һ�б߿�
		{
			printf("��");
			for (k = 0; k < SIZE; k++)
			{
				printf(" ��");
			}
			printf("����\n");
		}
		for (j = 0; j < SIZE; j++) //�����ͼ����
		{
			if (j == 0)
			{
				printf("�� ");
			}
			if (i == cursor.r && j == cursor.c) //�����ǰ��Ϸ������������
			{
				SetConsoleTextAttribute(stdOutput, FOREGROUND_BLUE); //���¸��ַ�����ɫ��Ϊ��ɫ
			} 
			switch (map[i][j])
			{
			case -1: case -2: printf("��"); break; //ûɨ���ĵط��á���ʾ
			case -3: case -4: printf("��"); break; //��ǹ��ĵط��á��ʾ
			case 9: 
				SetConsoleTextAttribute(stdOutput, FOREGROUND_RED); //���¸��ַ�����ɫ��Ϊ��ɫ
				printf("��"); 
				SetConsoleTextAttribute(stdOutput,
					FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //���û�ȥԭ������ɫ
				break; //��ʾ���������ú�ɫ�ġ��ʾ
			default: printf("%02d", map[i][j]); //�Ѿ�ɨ���ĵط������ֱ�ʾ��Χ�׵�����
			}
			if (j == SIZE - 1)
			{
				printf("��");
			}
			if (i == cursor.r && j == cursor.c)
			{
				SetConsoleTextAttribute(stdOutput, 
					FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //���û�ȥԭ������ɫ
			}
		}
		printf("\n");
		if (i == SIZE - 1) //������һ�б߿�
		{
			printf("��");
			for (k = 0; k < SIZE; k++)
			{
				printf(" ��");
			}
			printf("����\n");
		}
	}
}
int process(int command, point * cursor, int * remain, char map[][SIZE]) //���������ָ�����ֵ-1������Ϸ����
//1������Ϸʤ��
{
	int i, j;
	switch (command)
	{
	case 'j': case 'J': 
		if (map[cursor->r][cursor->c] == -1) //����ǰ�ȫ�������������Χ���׵��������Լ��ж��Ƿ���Ϸʤ��
		{
			map[cursor->r][cursor->c] = getMineNum(*cursor, map);
			(*remain)--; 
			if (*remain == 0) //���û����Ҫɨ����������ʤ��
			{
				return 1;
			}
		}
		else if (map[cursor->r][cursor->c] == -2) //������ף���Ϸ��������ʾ����δɨ�����������
		{
			for (i = 0; i < SIZE; i++)
			{
				for (j = 0; j < SIZE; j++)
				{
					if (map[i][j] == -2 || map[i][j] == -4) //������ף�����ʾ����
					{
						map[i][j] = 9;
					}
				}
			}
			return -1;
		} break;
	case ' ': 
		if (map[cursor->r][cursor->c] == -1 || map[cursor->r][cursor->c] == -2) //���δ�����
		{
			map[cursor->r][cursor->c] -= 2; //���õ���
		} 
		else if (map[cursor->r][cursor->c] == -3 || map[cursor->r][cursor->c] == -4) //����Ѿ������
		{
			map[cursor->r][cursor->c] += 2; //ȡ���õ�ı��
		} break;
	case 'A': case 'a': cursor->c -= cursor->c > 0 ? 1 : 0; break; //�������
	case 'S': case 's': cursor->r += cursor->r < SIZE -1 ? 1 : 0; break; //�������
	case 'D': case 'd': cursor->c += cursor->c < SIZE - 1 ? 1 : 0; break; //�������
	case 'W': case 'w': cursor->r -= cursor->r > 0 ? 1 : 0; break; //�������
	}
	return 0;
}
int getMineNum(point center, char map[][SIZE]) //����center����Χ��������
{
	int i, j, k, l, m, n, x = center.r, y = center.c, counter = 0;
	//�����center����Χ�ķ�Χ��iΪ�ϱ߽磬jΪ�±߽磬kΪ��߽磬lΪ�ұ߽�
	i = 0 < x - 1 ? x - 1 : 0, j = SIZE - 1 > x + 1 ? x + 1 : SIZE - 1;
	k = 0 < y - 1 ? y - 1 : 0, l = SIZE - 1 > y + 1 ? y + 1 : SIZE - 1;
	for (m = i; m <= j; m++)
	{
		for (n = k; n <= l; n++)
		{
			if (map[m][n] == -2 || map[m][n] == -4)
			{
				counter++;
			}
		}
	}
	return counter;
}