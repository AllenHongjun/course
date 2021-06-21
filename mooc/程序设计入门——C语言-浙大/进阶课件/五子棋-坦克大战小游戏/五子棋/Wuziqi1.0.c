/********************************************************************************
*File name:Wuziqi1.0.c                                                          *
*Author:����                                                                    *
*Version:1.0                                                                    *
*Date:2018.04.13                                                                *
*Debug Environment:Visual Studio 2017                                           *
*Description:�˻��������ս����Դ���루C���ԣ���ʵ��AI����Ȩֵ�����ж��ַ�ʽ����*
*��ʱֻ�����Ӧ��updateWeight����ȡ��ע�ͣ���������ע�͡�                       *
*********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#define SIZE 15 //�������̴�С
#define SPACE 0 //��������û����Ϊ0
#define AI 1 //AI�µ���Ϊ1
#define PLAYER 2 //����µ���Ϊ2

typedef struct coordinate //��������Ľṹ��
{
	int x;
	int y;
} coordinate;

void init(char board[SIZE][SIZE]); //��Ϸ��ʼ��
void drawBoard(char board[SIZE][SIZE]); //��������
coordinate playerRound(char board[SIZE][SIZE]); //��һغ�
																   //������һ����������ж���Ϸ���������ֵ0������Ϸû����������ֵ1����ĳһ����ʤ������ֵ2����;�
int judge(coordinate lastCoordinate, char board[SIZE][SIZE]);
//AI�غ�,������ҵ�����λ��������������
coordinate AIRound(coordinate playerCoordinate, char board[SIZE][SIZE]);
//����Ȩֵ
void updateWeight(coordinate lastCoordinate, int weight[SIZE][SIZE],
	char board[SIZE][SIZE]);

int main()
{
	char board[SIZE][SIZE]; //��������
	coordinate lastCoordinate; //��һ�������
	int result; //���ڱ�����Ϸ�жϽ��

	init(board); //��Ϸ��ʼ��
	while (1)
	{
		lastCoordinate = playerRound(board); //��һغ�
		{
			drawBoard(board); //��������
			result = judge(lastCoordinate, board);//�ж���Ϸ���
			if (result == 1)
			{
				printf("���ʤ\n");
				break;
			}
			else if (result == 2)
			{
				printf("�;�\n");
				break;
			}
		}
		lastCoordinate = AIRound(lastCoordinate, board); //AI�غ�
		{
			drawBoard(board); //��������
			result = judge(lastCoordinate, board);//�ж���Ϸ���
			if (result == 1)
			{
				printf("AIʤ\n");
				break;
			}
			else if (result == 2)
			{
				printf("�;�\n");
				break;
			}
		}
	}
	system("pause");
}
void init(char board[SIZE][SIZE]) //��Ϸ��ʼ��
{
	srand((unsigned int)time(NULL)); //������������ӱ���
	memset(board, '\0', SIZE * SIZE); //���̳�ʼ��
	drawBoard(board); //��������
}
void drawBoard(char board[SIZE][SIZE]) //��������
{
	//����һ���㹻����ַ��������������ͼ�Σ�Ϊ�˷�ֹ��˸��
	static char buffer[SIZE * SIZE * 4];
	memset(buffer, '\0', SIZE * SIZE * 4);
	int i, j, counter, length = SIZE * SIZE * 4;
	counter = 0;
	system("cls"); //������
	counter += sprintf_s(buffer + counter, length - counter, "x\\y");
	for (i = 0; i < SIZE; i++)
	{
		counter += sprintf_s(buffer + counter, length - counter, "%2d", i % 10);
	}
	counter += sprintf_s(buffer + counter, length - counter, "\n");
	for (i = 0; i < SIZE; i++)
	{
		counter += sprintf_s(buffer + counter, length - counter, "%2d ", i);
		for (j = 0; j < SIZE; j++)
		{
			if (board[i][j] != SPACE)
			{
				if (board[i][j] == PLAYER) //�������ҵ�����
				{
					counter += sprintf_s(buffer + counter, length - counter, "��");
				}
				else //������AI������
				{
					counter += sprintf_s(buffer + counter, length - counter, "��");
				}
			}
			else
			{
				if (i == 0)
				{
					if (j == 0)
					{
						counter += sprintf_s(buffer + counter, length - counter, "�� ");
					}
					else if (j == SIZE - 1)
					{
						counter += sprintf_s(buffer + counter, length - counter, "��");
					}
					else
					{
						counter += sprintf_s(buffer + counter, length - counter, "�� ");
					}
				}
				else if (i == SIZE - 1)
				{
					if (j == 0)
					{
						counter += sprintf_s(buffer + counter, length - counter, "�� ");
					}
					else if (j == SIZE - 1)
					{
						counter += sprintf_s(buffer + counter, length - counter, "��");
					}
					else
					{
						counter += sprintf_s(buffer + counter, length - counter, "�� ");
					}
				}
				else
				{
					if (j == 0)
					{
						counter += sprintf_s(buffer + counter, length - counter, "�� ");
					}
					else if (j == SIZE - 1)
					{
						counter += sprintf_s(buffer + counter, length - counter, "��");
					}
					else
					{
						counter += sprintf_s(buffer + counter, length - counter, "�� ");
					}
				}
			}
		}
		counter += sprintf_s(buffer + counter, length - counter, "\n");
	}
	puts(buffer);
}
coordinate playerRound(char board[SIZE][SIZE]) //��һغ�
{
	coordinate coordinate; //���������������
	int x, y;
	while (1)
	{
		scanf_s("%d %d", &x, &y);
		if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y] != SPACE)
		{
			printf("���벻�Ϸ�\n");
			while (getchar() != '\n');
		}
		else
		{
			coordinate.x = x; //������������ת��Ϊ
			coordinate.y = y; //���������̵�����
			break;
		}
	}
	board[coordinate.x][coordinate.y] = PLAYER;
	return coordinate;
}
//������һ����������ж���Ϸ���������ֵ0������Ϸû����������ֵ1����ĳһ����ʤ������ֵ2����;�
int judge(coordinate lastCoordinate, char board[SIZE][SIZE])
{
	int i, j, k, l, n, m, counter, x = lastCoordinate.x, y = lastCoordinate.y;
	char flag = board[x][y]; //��һ�����������һ����
							 //�����ɨ��ľ��η�Χ��iΪ�ϱ߽磬jΪ�±߽磬kΪ��߽磬lΪ�ұ߽�
	i = 0 < x - 4 ? x - 4 : 0, j = SIZE - 1 > x + 4 ? x + 4 : SIZE - 1;
	k = 0 < y - 4 ? y - 4 : 0, l = SIZE - 1 > y + 4 ? y + 4 : SIZE - 1;
	//�����ж��Ƿ�����������
	counter = 0;
	for (n = k; n <= l; n++)
	{
		if (board[x][n] == flag)
		{
			counter++;
		}
		else
		{
			counter = 0;
		}
		if (counter >= 5)
		{
			return 1;
		}
	}
	//�����ж��Ƿ�����������
	counter = 0;
	for (m = i; m <= j; m++)
	{
		if (board[m][y] == flag)
		{
			counter++;
		}
		else
		{
			counter = 0;
		}
		if (counter >= 5)
		{
			return 1;
		}
	}
	//�����ж��Ƿ�����������
	counter = 0;
	for (m = i; m <= j; m++)
	{
		for (n = k; n <= l; n++)
		{
			if (x - m == y - n)
			{
				if (board[m][n] == flag)
				{
					counter++;
				}
				else
				{
					counter = 0;
				}
			}
			if (counter >= 5)
			{
				return 1;
			}
		}
	}
	//Ʋ���ж��Ƿ�����������
	counter = 0;
	for (m = i; m <= j; m++)
	{
		for (n = k; n <= l; n++)
		{
			if (x - m == n - y)
			{
				if (board[m][n] == flag)
				{
					counter++;
				}
				else
				{
					counter = 0;
				}
			}
			if (counter >= 5)
			{
				return 1;
			}
		}
	}
	//�ж��Ƿ�;�
	for (m = 0; m < SIZE - 1; m++)
	{
		for (n = 0; n < SIZE - 1; n++)
		{
			if (board[m][n] == SPACE) //������̻��п�λ����ô��Ϸû�н���
			{
				return 0;
			}
		}
	}
	return 2; //���û�п�λ�ˣ���ô����
}
//AI�غ�
coordinate AIRound(coordinate LastCoordinate, char board[SIZE][SIZE])
{
	int i, j, maxWeight = 0, counter = 0;
	static int weight[SIZE][SIZE] = { 0 }; //�ֲ���̬���飬���ڱ���Ȩֵ
	coordinate coordinate; //����AI��������
	//AIÿ������ǰ�����ȸ��������һ������λ��������Ȩֵ����ѡ��Ȩֵ���ĵ������壬�������ٴθ���Ȩֵ
	updateWeight(LastCoordinate, weight, board); //�ȸ���Ȩֵ
	for (i = 0; i < SIZE; i++) //������Ȩֵ���Լ����Ȩֵ�ĵ�ĸ���
	{
		for (j = 0; j < SIZE; j++)
		{
			if (weight[i][j] > maxWeight)
			{
				maxWeight = weight[i][j];
				counter = 1;
			}
			else if (weight[i][j] == maxWeight)
			{
				counter++;
			}
		}
	}
	//�����Ȩֵ�������ѡȡһ����Ϊ�����
	int temp = rand() % counter + 1;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (weight[i][j] == maxWeight)
			{
				temp--;
				if (temp == 0)
				{
					coordinate.x = i;
					coordinate.y = j;
					goto outer;
				}
			}
		}
	}
outer:
	board[coordinate.x][coordinate.y] = AI;
	updateWeight(coordinate, weight, board); //�ٴθ���Ȩֵ
	return coordinate;
}
//����Ϊ���updateWeight������Լ����СȨֵΪ-1����ʾ�ĵ��������ӣ�
//�����򵥣�AIҲ���޴�
/*void updateWeight(coordinate lastCoordinate, int weight[SIZE][SIZE],
char board[SIZE][SIZE])
{
int x = lastCoordinate.x, y = lastCoordinate.y, i, j, k, l, m, n;
weight[x][y] = -1;
//�����Ȩֵ��Ӱ�쵽������iΪ�ϱ߽磬jΪ�±߽磬kΪ��߽磬lΪ�ұ߽�
i = 0 < x - 4 ? x - 4 : 0, j = SIZE - 1 > x + 4 ? x + 4 : SIZE - 1;
k = 0 < y - 4 ? y - 4 : 0, l = SIZE - 1 > y + 4 ? y + 4 : SIZE - 1;
for (m = i; m <= j; m++)
{
for (n = k; n <= l; n++)
{
weight[m][n]++; //��򵥵�Ȩֵ���㷽����ÿ��Ӱ�쵽һ�Σ�Ȩֵ��һ
}
}
}*/
void updateWeight(coordinate lastCoordinate, int weight[SIZE][SIZE],
	char board[SIZE][SIZE])
{
	int x = lastCoordinate.x, y = lastCoordinate.y, i, j, k, l, m, n, o, p, counter;
	weight[x][y] = -1;
	//�����Ȩֵ��Ӱ�쵽������iΪ�ϱ߽磬jΪ�±߽磬kΪ��߽磬lΪ�ұ߽�
	i = 0 < x - 4 ? x - 4 : 0, j = SIZE - 1 > x + 4 ? x + 4 : SIZE - 1;
	k = 0 < y - 4 ? y - 4 : 0, l = SIZE - 1 > y + 4 ? y + 4 : SIZE - 1;
	for (m = i; m <= j; m++)
	{
		for (n = k; n <= l; n++) //��Ȩֵ��Ӱ�쵽�ĵ���б���
		{
			//����õ�û�����壬��ôȨֵ����һ���������֮�����ɷ��ȵ���
			if (board[m][n] == SPACE)
			{
				if (m == x || n == y || abs(m - x) == abs(n - y)) //��֤��ͬһ��ֱ����
				{
					weight[m][n] += (int)(6 / sqrt((m - x) * (m - x) + (n - y) * (n - y)));
				}
			}
			//����õ��Ѿ�������Ե��壬��ô���������һ�������֮��ĵ�Ȩֵ��ȥһ�����������ɷ��ȣ�
			//����Ե����������ȵ���
			else if (board[m][n] != board[x][y])

			{
				counter = 1;
				for (o = x > m ? m : x; o < x || o < m; o++)
				{
					for (p = y > n ? n : y; p < y || p < n; p++) //��������֮��ĵ�
					{
						if (board[o][p] == SPACE)
						{
							weight[o][p] -= (int)(5 * counter / sqrt((o - x) * (o - x) + (p - y) * (p - y)));
						}
						else if (board[o][p] != board[x][y])
						{
							counter++;
						}
						else
						{
							goto outer1;
						}
						if (weight[o][p] < 0)
						{
							weight[o][p] = 0;
						}
					}
				}
			outer1:;
			}
			//����õ��Ѿ�������ͬ�����ӣ���ô���������һ�������֮��ĵ�Ȩֵ����һ�������ɷ��ȣ�
			//����ͬ�����������ȵ���
			else				
			{
				counter = 1;
				for (o = x > m ? m : x; o < x || o < m; o++)
				{
					for (p = y > n ? n : y; p < y || p < n; p++) //��������֮��ĵ�
					{
						if (board[o][p] == SPACE)
						{
							weight[o][p] += (int)(6 * counter / sqrt((o - x) * (o - x) + (p - y) * (p - y)));
						}
						else if (board[o][p] == board[x][y])
						{
							counter++;
						}
						else
						{
							goto outer2;
						}
					}
				}
			outer2:;
			}
		}
	}
}