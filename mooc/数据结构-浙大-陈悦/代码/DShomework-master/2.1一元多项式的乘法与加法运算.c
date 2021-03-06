/*
设计函数分别求两个一元多项式的乘积与和。

输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入样例:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0

code:

*/


#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node{
    int cof;
    int exp;
    struct Node* Next;
}Lnode , *PtrToLNode;
typedef PtrToLNode List;

List Creat(int num);
void Insert( List L, int cof, int exp);
int Compare( int exp1 , int exp2 );
void Attach( int cof , int exp , List * pRear );
List Sum( List L1 , List L2 );
List Mul( List L1 , List L2 );
void PrintL( List L);

int main(){
 	int num1;
 	scanf("%d",&num1);
 	List c1 = Creat(num1);

 	int num2;
 	scanf("%d",&num2);
 	List c2 = Creat(num2);
 	
 	List c3 = Mul( c1 , c2 );
	List c4 = Sum( c1 , c2 );
	
	PrintL(c3);
	PrintL(c4);

 	return 0;
}
 
List Creat(int num){
	List  c;
 	c = (List)malloc(sizeof(Lnode));
 	c->Next = NULL;
 	int i;
 	for(i = 0 ; i < num ; i++){
 		int cof;
    	int exp;
    	scanf("%d %d",&cof,&exp);
 		Insert(c, cof , exp );
	 }
	 return c;
}
void Insert( List L, int cof, int exp){
	List rear, temp;
	temp = L;
	rear = (List)malloc(sizeof(Lnode));
	rear->cof = cof;
	rear->exp = exp;
	rear->Next = NULL;
	
	while(temp->Next){
		temp = temp->Next;
	} 
	temp->Next = rear;
}
void PrintL( List L){
	List temp = L;
	temp = temp->Next;
	if(temp){
	do{
		printf("%d %d", temp->cof , temp->exp);
		if(temp->Next){
			printf(" ");
		}else{
			printf("\n");
		}
		temp = temp->Next;
	}while(temp);
	}else printf("0 0\n");
}
int Compare( int exp1 , int exp2 ){
	if( exp1 > exp2) return 1;
	if( exp1 < exp2) return -1;
	if( exp1 == exp2) return 0;
}
void Attach( int cof , int exp , List * pRear ){
	List p;
	p = (List)malloc(sizeof(Lnode));
	p->cof = cof;
	p->exp = exp;
	p->Next = NULL;
	(*pRear)->Next = p;
	*pRear = p;
}
List Sum( List L1 , List L2 ){
	List front,rear;
	int sum;
	rear = (List)malloc(sizeof(Lnode));
	front = rear;
	front->Next = NULL;
	L1 = L1->Next;
	L2 = L2->Next;
	while( L1 && L2 ){
		switch( Compare( L1->exp , L2->exp ) ) {
			case 1:
				Attach ( L1->cof, L1->exp, &rear);
				L1 = L1->Next;
				break;
			case -1:
				Attach( L2->cof, L2->exp, &rear);
				L2 = L2->Next;
				break;
			case 0:
				sum = L1->cof + L2->cof ;
				if(sum != 0) Attach( sum, L1->exp, &rear);
				L1 = L1->Next;
				L2 = L2->Next;
				break;
		}
	}
	for(; L1 ; L1= L1->Next){
		Attach ( L1->cof, L1->exp, &rear);
	}
	for(; L2 ; L2= L2->Next){
		Attach ( L2->cof, L2->exp, &rear);
	}
	rear->Next = NULL;
	return front;
}
List Mul( List L1 , List L2 ){
	List t1 = L1->Next;
	List front = (List)malloc(sizeof(Lnode));
	front->Next = NULL;
	
	while(t1){
		List t2 = L2->Next ;
		List p = (List)malloc(sizeof(Lnode));
		List Rear = p;
		p->Next = NULL;
		while(t2){
			Attach(t1->cof * t2->cof , t1->exp + t2->exp , &Rear);
			t2 = t2->Next;
		}
		front =  Sum( front , p);
		t1 = t1->Next;
	}
	
	return front;
}
