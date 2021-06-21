/* p.356 #6 */

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define IS_FULL(ptr) (!(ptr))

#define MAX_DIGIT  32 /* for long int */
#define RADIX_SIZE  2

/* BIT(x,i) extracts the i-th bit (counting from left to right) of x */
#define BIT(x, i)  ( (x>>(MAX_DIGIT-i-1)) & 1 )
/* right-shift x by n bits is equivalent to divide x by 2^n */
/* but is much faster than division */

typedef struct list_node  *list_pointer;
typedef struct list_node {
    long int  key;
	/* other fields can be defined here */
    list_pointer  link;
};

list_pointer new_node()
{
	list_pointer temp;

	temp = (list_pointer)malloc(sizeof(struct list_node));
	if (IS_FULL(temp)) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	return temp;
}

list_pointer radix_sort(list_pointer ptr)
/* Radix Sort using a linked list */
{
	list_pointer front[RADIX_SIZE], rear[RADIX_SIZE];
	int i, j, digit;
	for (i = MAX_DIGIT-1; i>=0; i--) {
		for (j=0; j<RADIX_SIZE; j++)
			front[j] = rear[j] = NULL;
		while (ptr) {
			digit = BIT(ptr->key, i); /* digit = ptr->key[i]; */
			if (!front[digit])
				front[digit] = ptr;
			else
				rear[digit]->link = ptr;
			rear[digit] = ptr;
			ptr = ptr->link;
		}
		/* reestablish the linked list for the next pass */
		ptr = NULL;
		for (j = RADIX_SIZE-1; j>=0; j--)
			if (front[j]) {
				rear[j]->link = ptr;
				ptr = front[j];
			}
	}
	return ptr;
}

long int atopl(char string[], int l)
/* convert string[l] to non-negative long int */
{
	long int key = -1;
	int i;

	if ((l>0) && (l<=10)) {
		for (i=0; i<l; i++) 
			if (!isdigit(string[i]))
				return -1;
		if ((l==10) && ((string[0]-'0')>2))
			return -1;
		key = atol(string+1);
		if ((l==10) && ((string[0]-'0')==2) && (key>147483647))
			return -1;
		return atol(string);
	}
	return -1;
}

list_pointer read_list()
{
	list_pointer head = NULL, tail = NULL, temp;
	char in[10]={""};
	long int key;
	int l;

	printf("Please enter the integers in [0, 2147483647].\n");
	printf("Any out-of-range input will finish the list input.\n\n");
	do {
		l = 0;
		do {
			in[l++] = getchar();
		} while ((l<=10)&&(in[l-1]!='\n'));
		if (in[l-1]!='\n')
			key = -1;
		else { 
			in[--l]='\0';
			key = atopl(in, l);
			if (key >= 0) {
				temp = new_node();
				temp->key = key;
				temp->link = NULL;
				if (!head)
					head = temp;
				else
					tail->link = temp;
				tail = temp;
			}
		}
	}while (key>=0);
	return head;
}

void print_free_list(list_pointer ptr)
{ /* free node after printing the key */
	list_pointer temp;
	while (ptr) {
		printf("%ld\n", ptr->key);
		temp = ptr;
		ptr = ptr->link;
		free(temp);
	}
}

int main()
{ /* a simple test */
	list_pointer list;

	list = read_list();
	list = radix_sort(list);
	print_free_list(list);

	return 0;
}
