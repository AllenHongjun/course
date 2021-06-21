/* p.366 #4 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1001 /* maximum size of list plus one */
#define SWAP(x, y, t)  ((t)=(x), (x)=(y), (y)=(t))

typedef struct {
	int key;
	/* other fields */
} element;

void quicksort (element list[], int table[], int left, int right)
{  /* sort list[] but move the elements of table[] only */
	int pivot, i, j;
	int temp;

	if (left < right) {
		i = left; j = right+1;
		pivot = list[ table[left] ].key; /* the index of list[] element is in table[]*/
		do { /* similar to the program in book, replace i by table[i] */
			do
				i++;
			while ((i<j) && (list[ table[i] ].key < pivot));
			do
				j--;
			while (list[ table[j] ].key > pivot);
			if (i < j)
				SWAP(table[i], table[j], temp);
		} while (i < j);
		SWAP(table[left], table[j], temp);
		quicksort(list, table, left, j-1);
		quicksort(list, table, j+1, right);
	}
}

void table_sort(element list[], int n, int table[])
{ /* copied from book */
	int i, current, next;
	element temp;

	for (i=0; i<n-1; i++)
		if (table[i] != i) {
			temp = list[i];
			current = i;
			do {
				next = table[current];
				list[current] = list[next];
				table[current] = current;
				current = next;
			} while (table[current] != i);
			list[current] = temp;
			table[current] = current;
		}
}

void sort_by_quicksort_and_table ( element list[], int n)
{  int i, table[MAX_SIZE];
   for (i=0; i<n; i++)
     table[i] = i;  /* initialize table */
   quicksort(list, table, 0, n-1);
   table_sort(list, n, table);
}

int atopi(char string[], int l)
/* convert string[l] to non-negative int */
{
	int key = -1;
	int i;

	if ((l>0) && (l<=5)) {
		for (i=0; i<l; i++) 
			if (!isdigit(string[i]))
				return -1;
		if ((l==5) && ((string[0]-'0')>3))
			return -1;
		key = atoi(string+1);
		if ((l==5) && ((string[0]-'0')==3) && (key>2767))
			return -1;
		return atoi(string);
	}
	return -1;
}

int read_list(element *list)
{
	char in[5]={""};
	long int key;
	int n = 0, l;

	printf("Please enter the integers in [0, 32767].\n");
	printf("Any out-of-range input will finish the list input.\n\n");
	do {
		l = 0;
		do {
			in[l++] = getchar();
		} while ((l<=5)&&(in[l-1]!='\n'));
		if (in[l-1]!='\n')
			key = -1;
		else { 
			in[--l]='\0';
			key = atopi(in, l);
			if (key >= 0) 
				list[n++].key = key;
		}
	}while (key>=0);
	return n;
}

void print_list(element list[], int n)
{
	int i;
	for (i=0; i<n; i++)
		printf("%d\n", list[i].key);
}

int main()
{
	element list[MAX_SIZE];
	int n;

	n = read_list(list);
	sort_by_quicksort_and_table (list, n);
	print_list(list, n);

	return 0;
}
