/*This time let us consider the situation in the movie "Live and Let Die" in which James Bond, the world's most famous spy, was captured by a group of drug dealers. He was sent to a small piece of land at the center of a lake filled with crocodiles. 
There he performed the most daring action to escape -- he jumped onto the head of the nearest crocodile! 
Before the animal realized what was happening, James jumped again onto the next big head... Finally he reached the bank before the last crocodile could bite him (actually the stunt man was caught by the big mouth and barely escaped with his extra thick boot).

Assume that the lake is a 100 by 100 square one. 
Assume that the center of the lake is at (0,0) and the northeast corner at (50,50). 
The central island is a disk centered at (0,0) with the diameter of 15. 
A number of crocodiles are in the lake at various positions. 
Given the coordinates of each crocodile and the distance that James could jump, you must tell him whether or not he can escape.

Input Specification:
Each input file contains one test case. Each case starts with a line containing two positive integers N (≤100), the number of crocodiles, and D, the maximum distance that James could jump. Then N lines follow, each containing the (x,y) location of a crocodile. Note that no two crocodiles are staying at the same position.

Output Specification:
For each test case, print in a line "Yes" if James can escape, or "No" if not.

Sample Input 1:
14 20
25 -15
-25 28
8 49
29 15
-35 -2
5 28
27 -29
-8 -28
-20 -35
-25 -20
-13 29
-30 15
-35 40
12 12
Sample Output 1:
Yes

Sample Input 2:
4 13
-12 12
12 12
-12 -12
12 -12
Sample Output 2:
No

code:
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define Max 100
typedef struct Point{
	int x, y;
}Position;

bool DFS(Position Lake[], int i, int N,int D);
bool FisrtJump(int x, int y, int D);
bool IsSafe(int x, int y, int D);
bool Jump(int i, int j, int x, int y, int D);
int Visited[Max] = { false };

int main(){
	Position Lake[Max];
	int N, D;
	scanf("%d %d", &N, &D);
	int i;
	for (i = 0; i < N; i++){//读入所有顶点，没有边
		scanf("%d %d", &Lake[i].x, &Lake[i].y);
	}
	bool answer = false;
	for (i = 0; i < N; i++){
		if (!Visited[i] && FisrtJump(Lake[i].x, Lake[i].y,D)){
			answer = DFS(Lake,i,N,D);
			if (answer ) break;
		}
	}
	if (answer ) printf("Yes\n");
	else printf("No\n");
	return 0;
}

bool FisrtJump(int x, int y, int D){
	double distance;
	distance = sqrt(pow(x , 2) + pow(y , 2));
	if ((distance - 7.5) <= D) return true;
	else return false;
}
bool IsSafe(int x, int y, int D){
	if ((x <= -(50 - D) || x >= (50 - D)) || (y <= -(50 - D) || y >= (50 - D)))
		return true;
	else return false;
}
bool Jump(int i, int j, int x, int y, int D){
	double distance;
	distance = sqrt(pow(x - i, 2) + pow(y - j, 2));
	if (distance <= D) return true;
	else return false;
}
bool DFS(Position Lake[], int i, int N,int D){
	bool answer = false;
	Visited[i] = true;
	if (IsSafe(Lake[i].x, Lake[i].y, D)) answer = true;
	else{
		int cnt;
		for (cnt = 0; cnt < N; cnt++){
			if (!Visited[cnt] && Jump(Lake[i].x, Lake[i].y, Lake[cnt].x, Lake[cnt].y, D)){
				answer = DFS(Lake, cnt, N, D);
				if (answer ) break;
			}
		}
	}
	return answer;
}
