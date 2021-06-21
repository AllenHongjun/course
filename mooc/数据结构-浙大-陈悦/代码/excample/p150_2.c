/* p.150 #2 */

#include <stdio.h>
#include <malloc.h>

#define IS_FULL(ptr) (!(ptr))
#define ERROR_KEY -1
#define MAX_EXPR 10

typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand}
        precedence;
typedef enum {FALSE, TRUE} boolean;

typedef struct stack {
	precedence token;
	struct stack *next;
};
typedef struct stack *stack_pointer;

char expr[MAX_EXPR];

void push(stack_pointer *top, precedence token)
{
	stack_pointer temp = (stack_pointer)malloc(sizeof(struct stack));
	if (IS_FULL(temp)) {
		printf("Memory FULL.\n");
		exit(1);
	}
	temp->token = token;
	temp->next = *top;
	*top = temp;
}

precedence pop(stack_pointer *top)
{
	stack_pointer temp = *top;
	precedence token;

	if (!temp) {
		printf("Stack is empty.\n");
		return ERROR_KEY;
	}
	token = temp->token;
	*top = temp->next;
	free(temp);
	return token;
}

precedence get_token(char *symbol, int *n)
{
	*symbol = expr[(*n)++];
	switch (*symbol) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case ' ': return eos;
	default: return operand;
	}
}

boolean paren_check()
{
	char symbol;
	int n = 0;
	stack_pointer top = NULL;
	precedence token;

	for (token=get_token(&symbol, &n); token!=eos; token=get_token(&symbol, &n)) 
		if (token == lparen)
			push(&top, token);
		else 
			if (token == rparen) 
				if (pop(&top)==ERROR_KEY)
					return FALSE;
	if (top)
		return FALSE;
	else 
		return TRUE;
}

main()
{
	printf("enter expression: ");
	scanf("%s", expr);
	if (paren_check())
		printf("Pass.\n");
	else
		printf("Wrong.\n");
}
