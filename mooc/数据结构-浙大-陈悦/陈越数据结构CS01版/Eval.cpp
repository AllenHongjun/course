#include <stdio.h>
#include <string.h>
#define PLUS   16
#define MINUS  17
#define TIMES  32
#define DIVIDE 33
#define MOD    34
#define EOS    -1
#define LPAREN -2
#define RPAREN -3
#define MAX_PRECEDENCE 48
#define MAX_SIZE 1000

int stack[1000];
int top = -1;

int get_token(char*, int*);
void postfix(char*);
int push(int);
int pop();
void print_token(int);

void main()
{
    char expr[100];
    scanf("%s",expr);
    expr[strlen(expr)]=' ';
    postfix(expr);
}

void postfix(char *expr)
{ /* translate expr from infix to postfix */
    int n=0;
    int token,temp;
    int flag=0;
    push (EOS);  /*place eos on stack*/
    for (token = get_token(expr, &n); token != EOS;
	 token = get_token(expr, &n) )
    {
	if      (token <= '9' && token >= '0' ||
		 token >= 'a' && token <= 'z' ||
		 token >= 'A' && token <= 'Z') /* if token == operand */
	    printf("%c", token);
	else if (token == LPAREN)
	    /* raise the precedences of coming operators */
	    flag += MAX_PRECEDENCE;
	else if (token == RPAREN)
	    /* lower the precedences */
	    flag -= MAX_PRECEDENCE;
	else
	{   /* remove and print symbols whose precedence is greater
	    or equal to the current token's */
	    token += flag;
	    for (temp = pop(); (temp>>4) >= (token>>4); temp = pop() )
		/* if the token is higher than the one in stack */
		/* Without stack[] here for safety */
		print_token(temp);

	    push (temp);
	    push (token);
	}
    }
    while ( (token = pop()) != EOS)
	print_token(token);
    printf ("\n");
}



int get_token(char *expr, int *n)
{
    int symbol = expr[(*n)++];
    switch(symbol)
    {
	case '(': return LPAREN;
	case ')': return RPAREN;
	case '+': return PLUS;
	case '-': return MINUS;
	case '*': return TIMES;
	case '/': return DIVIDE;
	case '%': return MOD;
	case ' ': return EOS;
	default : return symbol;
    }
}
int push(int x)
{
    if (top == MAX_SIZE-1) return -1;
    stack[++top]=x;
    return top+1;
}
int pop()
{
    if (top == -1 ) return -1;
    return stack[top--];
}
void print_token(int token)
{
    char temp;
    switch (token % MAX_PRECEDENCE)
    {
	case PLUS  : temp = '+'; break;
	case MINUS : temp = '-'; break;
	case TIMES : temp = '*'; break;
	case MOD   : temp = '%'; break;
	case DIVIDE: temp = '/'; break;
	default:     printf(" %d ", token);return;
    }
    printf ("%c", temp);
}
