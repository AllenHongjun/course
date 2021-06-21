/* p.224 #3 */

#include <stdio.h>

#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)
typedef enum {FALSE, TRUE} boolean;

typedef struct {
	int key;
	/* other fields */
} element;
element heap[MAX_ELEMENTS];
int n = 0;

void insert_max_heap(element item, int *n)
{ /* copied from book */
	int i;
	
	if (HEAP_FULL(*n)) {
		fprintf(stderr, "The heap is full.\n");
		exit(1);
	}
	i = ++(*n);
	while ((i!=1) && (item.key>heap[i/2].key)) {
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = item;
}

int find(int key, int n)
{ /* O(n) for finding key in heap[] with n elements */
	int i;

	for (i=1; i<=n; i++)
		if (heap[i].key == key)
			return i;
	return 0; /* 0 for not-found */
}

boolean change_priority(int old_key, int new_key, int in)
{ /* replace old_key by new_key and keep the resulting heap a max-heap */

	int index, child;
	element temp;

	if (!(index = find(old_key, n)))
		return FALSE; /* old_key is not found */
	
	temp = heap[index]; /* store the node to be changed */
	temp.key = new_key; /* change priority */

	if (new_key > old_key)
		while ((index!=1) && (new_key > heap[index/2].key)) {
			heap[index] = heap[index/2];
			index /= 2;
		} /* if new_key is larger, move it up if necessary */
		else if (new_key < old_key) { /* if new_key is smaller */
		child = index * 2;
		while (child <= n) {
			if ((child<n) && (heap[child].key<heap[child+1].key))
				child ++; /* find its larger child */
			if (new_key < heap[child].key) {
				heap[index] = heap[child];
				index = child;
				child *= 2;
			} /* move it down if necessary */
			else break;
		}
	}
	heap[index] = temp; /* save at the proper position */
	return TRUE; /* succeed */
}

void print_heap(int n)
{
	int i;

	for (i=1; i<=n; i++)
		printf("%d ", heap[i].key);
	printf("\n");
}

int main()
{ /* a simple test */
	char in;
	int key1, key2;
	element item;
	
	do {
		printf("1 = insert; 2 = change priority; 3 = print.\n");
		printf("Hit any other key to quit.\n");
		scanf("%c", &in); getchar(); /* get input + [Enter] */
		switch (in) {
		case '1':
			printf("Enter the key: ");
			scanf("%d", &item.key); getchar();
			insert_max_heap(item, &n);
			break;
		case '2':
			printf("Enter old key and new key: ");
			scanf("%d%d", &key1, &key2); getchar();
			if (!change_priority(key1, key2, n))
				fprintf(stderr, "The key %d is not found.\n", key1);
			break;
		case '3':
			print_heap(n);
			break;
		default:
			in = 0;
			break;
		}
	} while (in != 0);
	return 0;
}
