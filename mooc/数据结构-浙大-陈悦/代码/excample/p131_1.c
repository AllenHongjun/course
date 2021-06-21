/* P.131 #1 */

#include <stdio.h>

#define MEMORY_SIZE 10
#define ERROR_KEY -1

typedef struct {
	int key;
	/* other fields */
} element;

element memory[MEMORY_SIZE];
int top[2] = {-1, MEMORY_SIZE};

void push(int stack_no, element item)
{
	if (stack_no!=0 && stack_no!=1) {
		printf("ERROR: Illegal stack number!\n");
		return;
	}
	if (top[1]-top[0] <=2 ) {
		printf("ERROR: Memory Full.\n");
		return;
	}
	top[stack_no] += ((stack_no)? -1: 1);
	memory[top[stack_no]] = item;
}

element pop (int stack_no)
{
	element item;
	int boundary;

	item.key = ERROR_KEY;
	if (stack_no!=0 && stack_no!=1) 
		printf("ERROR: Illegal stack number!\n");
	else {
		boundary = (stack_no)? MEMORY_SIZE: -1;
		if (top[stack_no] != boundary) {
			item = memory[top[stack_no]];
			top[stack_no] -= ((stack_no)? -1: 1);
		}
	}
	return item;
}

main()
{
	element item;
	int in = -1;
	int stack_no;

	while (in) {
		printf("push = 1, pop = 2, top = 3, quit = 0: ");
		scanf("%d", &in);
		switch (in) {
		case 1:
			printf("Enter stack number and key: ");
			scanf("%d %d", &stack_no, &item.key);
			push (stack_no, item);
			break;
		case 2:
			printf("Enter stack number: ");
			scanf("%d", &stack_no);
			item = pop(stack_no);
			if (item.key==ERROR_KEY)
				printf("ERROR: Stack %d is empty.\n", stack_no);
			else 
				printf("Pop key = %d \n", item.key);
			break;
		case 3:
			printf("top0 = %d, top1 = %d \n", top[0], top[1]);
			break;
		default:
			break;
		}
	}
}


