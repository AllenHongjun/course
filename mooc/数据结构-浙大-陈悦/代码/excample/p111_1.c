/* p.111 #1 */

#include <stdio.h>

#define MAX_QUEUE_SIZE 5 /* maximum number of elements in a queue */
#define ERROR -1         /* the error key - there must be no such key in other elements */

typedef struct {
	int key;
	/* other fields */
} element;

element queue[MAX_QUEUE_SIZE];

int queue_full (int *front, int *rear)
{ /* for non-circular queue */
	int i;

	if (*rear-*front == MAX_QUEUE_SIZE) {
		fprintf(stderr, "The queue is full.\n");
		return 0; /* signal queue-full */
	}
	else { /* if not really full */
		for (i=0; *front<MAX_QUEUE_SIZE-1; i++)
			queue[i] = queue[++*front]; /* shift queue to the left end */
		/* reset rear and front */
		*rear = i - 1; 
		*front = -1;
		return 1; /* signal continue to push */
	}
}

element queue_empty (int *front, int *rear)
{ /* for non-circular queue */
	element temp;

	*front = *rear = -1; /* reset front and rear */
	temp.key = ERROR; /* signal empty */
	fprintf(stderr, "The queue is empty.\n");
	return temp; /* return error signal */
}

void pushq (int *front, int *rear, element item)
{ /* for non-circular queue */
	if (*rear == MAX_QUEUE_SIZE-1) 
		if (!queue_full(front, rear)) /* if queue is really full */
			return;
	queue[++*rear] = item; /* push */
}

element popq (int *front, int *rear)
{ /* for non-circular queue */
	if (*front == *rear) /* if queue is empty */
		return queue_empty(front, rear); /* reset front and rear and return error */
	return queue[++*front]; /* pop */
}

int main()
{ /* a simple test */
	int rear = -1;
	int front = -1;
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
		case 2: /* pop */
			temp = popq(&front, &rear);
			if (temp.key != ERROR)
				printf("Pop key = %d\n", temp.key);
			break;
		case 0: /* print current front and rear */
			printf("front = %d, rear = %d\n", front, rear);
		}
	} while (command==0 || command==1 || command==2);
	/* break at any illegal input */

	return 0;
}

