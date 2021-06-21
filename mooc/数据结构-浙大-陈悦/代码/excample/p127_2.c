/* p.127 #2 */

#include <stdio.h>

typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand}
        precedence;

void print_token (precedence token)
{
	char c;

	switch (token) {
	case lparen:	c = '('; break;
	case rparen:	c = ')'; break;
	case plus:		c = '+'; break;
	case minus:		c = '-'; break;
	case times:		c = '*'; break;
	case divide:	c = '/'; break;
	case mod:		c = '%'; break;
	case eos:		c = ' '; break;
	default:	fprintf(stderr, "Illegal operator!\n"); return;
	}
	printf("%c", c);
}

main()
{
	int i = 0;
	precedence expression[]={lparen, rparen, plus, minus, times, divide, 
		                     mod, eos, operand};
	while (*(expression+i) != operand) {
		print_token (*(expression+i++));
	}
}
