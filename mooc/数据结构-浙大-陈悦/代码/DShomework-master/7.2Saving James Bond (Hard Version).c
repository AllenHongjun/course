/*This time let us consider the situation in the movie "Live and Let Die" in which James Bond, the world's most famous spy, was captured by a group of drug dealers. 
He was sent to a small piece of land at the center of a lake filled with crocodiles.
There he performed the most daring action to escape -- he jumped onto the head of the nearest crocodile! 
Before the animal realized what was happening, James jumped again onto the next big head... 
Finally he reached the bank before the last crocodile could bite him (actually the stunt man was caught by the big mouth and barely escaped with his extra thick boot).

Assume that the lake is a 100 by 100 square one. 
Assume that the center of the lake is at (0,0) and the northeast corner at (50,50). 
The central island is a disk centered at (0,0) with the diameter of 15. 
A number of crocodiles are in the lake at various positions. Given the coordinates of each crocodile and the distance that James could jump, you must tell him a shortest path to reach one of the banks.
The length of a path is the number of jumps that James has to make.

Input Specification:
Each input file contains one test case.
Each case starts with a line containing two positive integers N (≤100), the number of crocodiles, and D, the maximum distance that James could jump.
Then N lines follow, each containing the (x,y) location of a crocodile. 
Note that no two crocodiles are staying at the same position.

Output Specification:
For each test case, if James can escape, output in one line the minimum number of jumps he must make. 
Then starting from the next line, output the position (x,y) of each crocodile on the path, each pair in one line, from the island to the bank. If it is impossible for James to escape that way, simply give him 0 as the number of jumps. 
If there are many shortest paths, just output the one with the minimum first jump, which is guaranteed to be unique.

Sample Input 1:
17 15
10 -21
10 21
-40 10
30 -50
20 40
35 10
0 -10
-25 22
40 -40
-30 30
-10 22
0 11
25 21
25 10
10 10
10 35
-30 10

Sample Output 1:
4
0 11
10 21
10 35
Sample Input 2:
4 13
-12 12
12 12
-12 -12
12 -12
Sample Output 2:
0

code:
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SuperBig 65535 
#define Max 101
typedef struct Point{
	int x, y;
}Position;

double DisFirs(int x, int y);//计算原点到所有点的距离
bool FirstJump(int x, int y);
bool IsSafe(int x, int y);
bool Jump(int i, int j, int x, int y);
void Unweighted(Position Lake[], int dist[], int path[], int S);

typedef struct QNode{
	int *Data;
	int Front, Rear;
	int MaxSize;
}*Queue;

Queue CreateQueue(int MaxSize);
bool IsEmpty(Queue Q);
void AddQ(Queue Q, int X);
int DeleteQ(Queue Q);

typedef struct Snode{//堆栈结构
	int data;
	struct Snode * next;
}*Prt;
typedef Prt Stack;

Stack Createstack();//建立堆栈
int Isempty(Stack S);//判空
void Push(Stack S, int X);//入栈
int Pop(Stack S);//出栈

Position Lake[Max];
int N, D;

int main(){
	scanf("%d %d", &N, &D);
	int i;
	Lake[0].x = Lake[0].y = 0;//Lake的第0号位置为（0.0）点
	for (i = 1; i < N + 1; i++){//读入所有顶点，没有边
		scanf("%d %d", &Lake[i].x, &Lake[i].y);
	}
	if (D >= (50 - 7.5)) printf("1\n");//跳一下直接就到了
	else{
		int *dist = (int*)malloc(sizeof(int)*(N + 1));
		int *path = (int*)malloc(sizeof(int)*(N + 1));
		for (i = 0; i < N + 1; i++){//初始化步骤数组和路径数组
			dist[i] = -1;
			path[i] = -1;
		}
		Unweighted(Lake, dist, path, 0);

		for (i = 0; i < N + 1; i++){
			if (dist[i] != -1) break;//有能跳到的点
		}
		if (i == N + 1)printf("0\n");
		else{
			int *safe = (int*)malloc(sizeof(int)*(N + 1));//可以跳上岸的点i
			for (i = 0; i < N + 1; i++) safe[i] = 0;
			for (i = 1; i < N + 1; i++) if (IsSafe(Lake[i].x, Lake[i].y)) safe[i] = 1;
			int *everydis = (int*)malloc(sizeof(int)*(N + 1));//原点到每个点的距离
			for (i = 1; i < N + 1; i++) everydis[i] = DisFirs(Lake[i].x, Lake[i].y);

			int dismin = SuperBig;
			int length = SuperBig;
			for (i = 1; i < N + 1; i++){
				if ((safe[i] == 1) && (dismin> dist[i]) && (dist[i] != -1)){ //在可以跳上岸的点中寻找dist最小的点i
					dismin = dist[i];
				}
			}
			Stack S = Createstack();//处理路径长度相同的问题，用堆栈找第一个跳点，比较everydis值寻找第一跳最短情况
			int index = false;//跳跃开始位置
			int flag = false;
			for (i = 1; i < N + 1; i++){
				if ((safe[i] == 1) && dismin == dist[i]){
					flag = true;//有能跳到岸上，且在路径上的点
					int top = i;
					while (dist[top] != 1){
						Push(S, top);
						top = path[top];
					}
					if (length > everydis[top]){//路径长度相同时，比较everydis值选更短的结点
						length = everydis[top];
						index = top;
					}
				}
			}
			if (!flag) printf("0\n");
			else{
				int indexF;
				while (1){
					indexF = Pop(S);
					if (dist[indexF] == dismin) break;
				}

				printf("%d\n", dismin + 1);

				Stack F = Createstack();
				int tp = indexF;
				while (dist[tp] != 0){
					Push(F, tp);
					tp = path[tp];
				}
				while (!Isempty(F)){
					int temp = Pop(F);
					printf("%d %d\n", Lake[temp].x, Lake[temp].y);
				}
			}
		}
	}
	return 0;
}

Queue CreateQueue(int MaxSize){
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (int *)malloc(MaxSize * sizeof(int));
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
}
void AddQ(Queue Q, int X){
	Q->Rear = (Q->Rear + 1) % (Q->MaxSize);
	Q->Data[Q->Rear] = X;
}
bool IsEmpty(Queue Q){
	return (Q->Front == Q->Rear);
}
int DeleteQ(Queue Q){
	Q->Front = (Q->Front + 1) % Q->MaxSize;
	return  Q->Data[Q->Front];
}
double DisFirs(int x, int y){
	return sqrt(pow(x, 2) + pow(y, 2));
}
bool IsSafe(int x, int y){
	if (((x >= fabs(50 - D)) && x<fabs(50)) ||
		((y >= fabs(50 - D)) && y<fabs(50)))
		return true;
	else return false;
}
bool Jump(int i, int j, int x, int y){
	double distance;
	distance = sqrt(pow(x - i, 2) + pow(y - j, 2));
	if (distance <= D) return true;
	else return false;
}
bool FirstJump(int x, int y){
	double distance;
	distance = sqrt(pow(x, 2) + pow(y , 2));
	if ((distance <= D + 7.5) && (distance > 7.5))//在岛上的鳄鱼也不算
		return true;
	else return false;
}
void Unweighted(Position Lake[], int dist[], int path[], int S){
	Queue Q;
	int V;
	Q = CreateQueue(Max);
	dist[S] = 0;
	AddQ(Q, S);
	while (!IsEmpty(Q)){
		V = DeleteQ(Q);
		int cnt;
		for (cnt = 1; cnt < N + 1; cnt++){
			if ((V == 0) && (dist[cnt] == -1) && FirstJump(Lake[cnt].x, Lake[cnt].y)){
				dist[cnt] = dist[V] + 1;
				path[cnt] = V;
				AddQ(Q, cnt);
			}
			if ((V!=0)&&(dist[cnt] == -1 )&&Jump(Lake[V].x, Lake[V].y, Lake[cnt].x, Lake[cnt].y)){
					dist[cnt] = dist[V] + 1;
					path[cnt] = V;
					AddQ(Q, cnt);
			}
		}
	}
}
Stack Createstack(){
	Stack S;
	S = (Stack)malloc(sizeof(struct Snode));
	S->next = NULL;
	return S;
}
int Isempty(Stack S){
	if (S->next == NULL) return 1;
	else return 0;
}
void Push(Stack S, int X){
	Prt TmpC = (Prt)malloc(sizeof(struct Snode));
	TmpC->data = X;
	TmpC->next = S->next;
	S->next = TmpC;
}
int  Pop(Stack S){
	Prt FstC;
	int  data;
	if (Isempty(S) == 0){
		data = S->next->data;
		FstC = S->next;
		S->next = FstC->next;
		return data;
	}
}
