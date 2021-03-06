/*Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L.
For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, 
a positive N (≤10^5) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. 
The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Data Next
where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:
For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1

/*伪码描述（带头节点）：
k // 反转k次
new //指向已经逆转好的头结点的位置 初始指向第一个结点（我们认为第一个结点是已经逆转好的）
old //指向当前还没有完成逆转的老链表的头结点
temp //指向old的下一个位置

Ptr Reverse(Prt head, int k){
    cnt = 1;
    new = head->next;
    old = new->next;
    while (cnt < k){
		temp = old->next;
        old->next = new;
        new = old;
        old = temp;
        cnt++;
    }
    head->next->next = old;
    return new;
}

测试数据：
1·有尾巴不反转 
2·地址取到上下届
3·正好全反转
4·k=n
5·k=1
6·最大（最后剩k-1不反转）、最小n
7·有多余结点
其中 2-6 为边界测试*/





#include <iostream>
using namespace std;
int main() {
	int data[100001] = { 0 }, next[100001] = { 0 };
	int f, n, k;
	cin >>f >>n >> k;
	int a, d, ne;
	for (int i = 0; i < n; i++) {
		cin >> a >> d >> ne;
		data[a] = d;
		next[a] = ne;
	}

	int sum = 0; //获取真正在链表上的结点数
	int t = f;
	while (t != -1) {
		sum++;
		t = next[t];
	}

	int now = f, old = next[f];
	int cnt = 1;
	while (cnt < k && cnt <sum) {  //先反转一次，得到整个链表的头结点
		int temp = next[old];
		next[old] = now;
		now = old;
		old = temp;
		cnt++;
	}
	next[f] = old;  
	int b = now; //记录第一次翻转后的头结点地址

	now = old;  //将now和old移向想一组要反转的链表第一个结点
	old = next[now];
	if (k != 1) {   //k=1就是不反转，没必要做以下操作，做了反而会是指针混乱
		int c = f; //记录下一组 k个元素 的头结点位置，也就是上一组的尾部
		int fro;
		for (int i = 1; i<sum / k && now != -1; i++) {
			fro = c;
			int count = 1;
			int flag = 0;  //防止下一组头结点位置丢失
			while (count < k) {
				if (!flag) {
					flag = 1;
					c = now; //更新下一组的头结点位置
				}
				int temp = next[old];
				next[old] = now;
				now = old;
				old = temp;
				count++;
			}
			next[fro] = now;
			now = old;
			old = next[now];
		}
		next[c] = now;  //如果不在反转了，将上组尾部链接的此后元素的头部
	}

	while (b != -1) {  //读元素
		printf("%05d %d ", b, data[b]);
		b = next[b];
		if (b == -1)printf("-1\n");
		else printf("%05d\n", b);
	}
	return 0;
}
