/*哈利·波特要考试了，他需要你的帮助。
这门课学的是用魔咒将一种动物变成另一种动物的本事。例如将猫变成老鼠的魔咒是haha，将老鼠变成鱼的魔咒是hehe等等。
反方向变化的魔咒就是简单地将原来的魔咒倒过来念，例如ahah可以将老鼠变成猫。
另外，如果想把猫变成鱼，可以通过念一个直接魔咒lalala，也可以将猫变老鼠、老鼠变鱼的魔咒连起来念：hahahehe。

现在哈利·波特的手里有一本教材，里面列出了所有的变形魔咒和能变的动物。
老师允许他自己带一只动物去考场，要考察他把这只动物变成任意一只指定动物的本事。
于是他来问你：带什么动物去可以让最难变的那种动物（即该动物变为哈利·波特自己带去的动物所需要的魔咒最长）需要的魔咒最短？
例如：如果只有猫、鼠、鱼，则显然哈利·波特应该带鼠去，因为鼠变成另外两种动物都只需要念4个字符；而如果带猫去，则至少需要念6个字符才能把猫变成鱼；同理，带鱼去也不是最好的选择。

输入格式:
输入说明：输入第1行给出两个正整数N (≤100)和M，其中N是考试涉及的动物总数，M是用于直接变形的魔咒条数。为简单起见，我们将动物按1~N编号。
随后M行，每行给出了3个正整数，分别是两种动物的编号、以及它们之间变形需要的魔咒的长度(≤100)，数字之间用空格分隔。
输出格式:
输出哈利·波特应该带去考场的动物的编号、以及最长的变形魔咒的长度，中间以空格分隔。如果只带1只动物是不可能完成所有变形要求的，则输出0。
如果有若干只动物都可以备选，则输出编号最小的那只。

输入样例:
6 11
3 4 70
1 2 1
5 4 50
2 6 50
5 6 60
1 3 70
4 6 60
3 6 80
5 1 100
2 4 60
5 2 80
输出样例:
4 70

code:
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxVertex 101   
#define INFINITY 65535  // ∞设为双字节无符号整数的最大值65535
typedef int Vertex;
typedef int WeightType;

typedef  struct ENode{
	Vertex V1, V2;
	WeightType Weight;
}*PtrToENode;
typedef PtrToENode Edge;

typedef struct GNode{
	int Nv;
	int Ne;
	WeightType G[MaxVertex][MaxVertex];
}*PtrToGNode;
typedef PtrToGNode MGraph;

MGraph CreateGraph(int VertexNum);
void InsertEdge(MGraph Graph, Edge E);
MGraph BuildGraph();
void Floyd(MGraph Graph, WeightType D[][MaxVertex]);
void FindAnimal(MGraph Graph, WeightType D[][MaxVertex]);

int main(){
	MGraph G = BuildGraph();
	WeightType D[MaxVertex][MaxVertex];
	Floyd(G, D);
	FindAnimal(G, D);
	return 0;
}

MGraph CreateGraph(int VertexNum){
	Vertex V, W;
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	//结点从1- N编号
	for (V = 1; V<Graph->Nv + 1; V++)
	for (W = 1; W<Graph->Nv + 1; W++)
		Graph->G[V][W] = INFINITY;
	return Graph;
}
void InsertEdge(MGraph Graph, Edge E){
	//无向图
	Graph->G[E->V1][E->V2] = E->Weight;
	Graph->G[E->V2][E->V1] = E->Weight;
}
MGraph BuildGraph(){
	MGraph Graph;
	Edge E;
	int Nv, i;
	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);
	scanf("%d", &(Graph->Ne));
	if (Graph->Ne != 0) { // 如果有边 
		E = (Edge)malloc(sizeof(struct ENode));
		for (i = 0; i<Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
	}
	return Graph;
}
void Floyd(MGraph Graph, WeightType D[][MaxVertex]){
	Vertex i, j, k;
	// 初始化 
	for (i = 1; i<Graph->Nv + 1; i++)
	for (j = 1; j<Graph->Nv + 1; j++) {
		D[i][j] = Graph->G[i][j];
	}
	for (k = 1; k<Graph->Nv + 1; k++)
	for (i = 1; i<Graph->Nv + 1; i++)
	for (j = 1; j<Graph->Nv + 1; j++)
	if (D[i][k] + D[k][j] < D[i][j]) {
		D[i][j] = D[i][k] + D[k][j];
	}
}
void FindAnimal(MGraph Graph, WeightType D[][MaxVertex]){
	int i, j;
	int MaxDis[MaxVertex] = { 0 };
	for (i = 1; i < Graph->Nv + 1; i++){
		int max = D[i][1];
		for (j = 1; j < Graph->Nv + 1; j++){
			if (max<D[i][j] && i != j) max = D[i][j];
		}
		MaxDis[i] = max;
	}
	int mindis = INFINITY;
	int index;
	for (i = 1; i < Graph->Nv + 1; i++){
		if (mindis>MaxDis[i]){
			mindis = MaxDis[i];
			index = i;
		}
	}
	if (mindis == INFINITY) printf("0\n");
	else printf("%d %d\n", index, MaxDis[index]);
}
