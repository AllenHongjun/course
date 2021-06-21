/* p.111 #2 */

#include <stdio.h>

#define MAX_QUEUE_SIZE 5 /* maximum no. of elements + 1 in a circular queue */
#define ERROR -1         /* the error key - there must be no such key in other elements */

typedef struct {
	int key;
	/* other fields */
} element;

element queue[MAX_QUEUE_SIZE];

void queue_full (int *rear)
{ /* for circular queue */
	fprintf(stderr, "The queue is full.\n"); /* queue must be full */
	/* reset rear */
	if (!*rear)
		*rear = MAX_QUEUE_SIZE - 1;
	else
		(*rear) -- ; 
}

element queue_empty (int *front, int *rear)
{/* for circular queue */
	element temp;

	*front = *rear = 0; /* reset front and rear */
	temp.key = ERROR; /* signal error */
	fprintf(stderr, "The queue is empty.\n");
	return temp; /* return error signal */
}

void pushq (int *front, int *rear, element item)
{/* for circular queue */
	*rear = (*rear + 1) % MAX_QUEUE_SIZE; /* increment rear first */
	if (*front == *rear) { /* if it's full */
		queue_full(rear);
		return;
	}
	queue[*rear] = item; /* push */
}

element popq (int *front, int *rear)
{/* for circular queue */
	if (*front == *rear) /* if empty */
		return queue_empty(front, rear); /* signal error */
	*front = (*front + 1) % MAX_QUEUE_SIZE; /* else increment front first */
	return queue[*front]; /* pop */
}

int main()
{/* a simple test */
	int rear = 0;
	int front = 0;
	int command;
	element temp;

	do {
		printf("0 = check, 1 = push, 2 = pop: ");
		scanf("%d", &command);
		switch (command) {
		case 1:  /* push */
			printf("Key of item = ");
			scanf("%d", &temp.key);
			pushq(&front, &rear, temp);
			break;
		case 2:  /* pop */
			temp = popq(&front, &rear);
			if (temp.key != ERROR)
				printf("Pop key = %d\n", temp.key);
			break;
		case 0:  /* print current front and rear */
			printf("front = %d, rear = %d\n", front, rear);
		}
	} while (command==0 || command==1 || command==2);
	/* break at any illegal input */

	return 0;
}

