/* p.146 #2 */

#include <stdio.h>
#include <malloc.h>

#define IS_FULL(ptr) (!(ptr))

typedef struct list_node {
	int data;
	struct list_node *next;
};
typedef struct list_node *list_pointer;

list_pointer search(list_pointer ptr, int num)
{
	for (; ptr && ptr->data!=num; ptr = ptr->next)
		;
	return ptr;
}

void insert_front(list_pointer *ptr, int num)
{
	list_pointer temp;
	list_pointer node = *ptr;

	temp = (list_pointer)malloc(sizeof(struct list_node));
	if (IS_FULL(temp)) {
		fprintf(stderr, "The memory is full.\n");
		return;
	}
	temp->data = num;
	temp->next = node;
	*ptr = temp;
}

main()
{
	list_pointer ptr = NULL;
	int in = -1;
	int num;
	list_pointer temp;

	while (in) {
		printf("insert = 1, search = 2, quit = 0: ");
		scanf("%d", &in);
		switch (in) {
		case 1:
			printf("insert num = ");
			scanf("%d", &num);
			insert_front(&ptr, num);
			break;
		case 2:
			printf("search num = ");
			scanf("%d", &num);
			temp = search(ptr, num);
			if (temp)
				printf("%d is found.\n", temp->data);
			else
				printf("%d is not found.\n", num);
			break;
		default:
			break;
		}
	}
	while (ptr) {
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
}
