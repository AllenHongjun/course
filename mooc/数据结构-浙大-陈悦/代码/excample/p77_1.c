/* p.77 #1 */

#include <stdio.h>

#define MAX_INT 32767
#define MAX_TERMS 101

typedef struct {
	int col;
	int row;
	int value;
} term;

term a[MAX_TERMS];

void read_matrix()
{
	int row, col, value;
	int index = 0; /* position of the coming new term in a[] */
	int i = 1; /* current number of nonzero terms + 1 */
	int j, k;
	char flag; /* for error handling */

	a[1].row = MAX_INT; /* initialize a[] so that the 1st term can be inserted */

/** read total row number and column number **/
	do {
		printf("Please enter the total row number: ");
		scanf("%d", &row);
	} while (row <= 0);
	a[0].row = row;
	do {
		printf("\nPlease enter the total column number: ");
		scanf("%d", &col);
	} while (col <= 0);
	a[0].col = col;
/*********************************************/

/** read nonzero entries **/
	printf("Please enter the nonzero entries: <row, col, value>\n");
	printf("Enter 0 0 0 to stop.\n");
	do {
		scanf("%d %d %d", &row, &col, &value);
		if (!(value || row || col)){ /* if 0 0 0 are entered*/
			a[0].value = i-1; /* set the total number of nonzero terms */
			return ;
		} /* Stop */
		if (row<0 || row>=a[0].row || col<0 || col>=a[0].col || !value){
			printf("ERROR: Illegal input. \n");
			printf("Please enter again, or input 0 0 0 to stop.\n");
		} /* check illegal input */
		else { /* legal input */
			for (j=1; j<i && a[j].row<row; j++) ; /* find the proper row-majored position*/
			if (j==i) index = i; /* the new term is to be attached at the end */
			else { /* 1 - have to make an insertion */
				if (a[j].row == row) { /* have to sort according to column in the same row */
					for (k=j; k<i && a[k].row == row && a[k].col<col; k++) ;
					if (k==i) index = i;
					else index = k;
				}
				else index = j; /* different row, insert directly */
			} /* end 1 */
			if (a[index].row != row || a[index].col != col) { /*if it's indeed a new term */
				for (j=i; j>index; j--) { /* shift array to make a space for the new term */
					a[j].row = a[j-1].row;
					a[j].col = a[j-1].col;
					a[j].value = a[j-1].value;
				}
				/* insert the new term */
				a[index].row = row;
				a[index].col = col;
				a[index].value = value;
				i++; /* count one in */
			}
			else { /* 2 - the term is not new */
				printf("ERROR: <%d, %d> = %d already exists.  Overwrite? (y/n)", 
					row, col, a[index].value);
				do {
					flag = getchar(); 
				} while (flag != 'y' && flag != 'n');
				if (flag == 'y') 
					a[index].value = value;
				printf("Please continue.\n");
			} /* end 2 */
		} /* end legal input */
	} while (i<MAX_TERMS);
	printf("ERROR: Overflow.\n");
}

void print_matrix()
{
	int i, j, k = 1;

	for (i=0; i<a[0].row; i++) {
		for (j=0; j<a[0].col; j++) {
			if (i!=a[k].row || j!=a[k].col)
				printf("0 "); /* don't forget to print the zero terms */
			else
				printf("%d ", a[k++].value);
		} /*end j-loop */
		printf("\n"); /* finish one row */
	} /* end i-loop */
}

int *search(int value)
{
	int index[MAX_TERMS]; /* store indices of all the terms with "value" */
	int i, counter = -1; /* position of the current term with "value" in index[] */

	for (i=1; i<=a[0].value; i++)  /* scan the matrix */
		if (a[i].value == value)
			index[++counter] = i; /* record the index */
	if (counter == -1) return NULL; /* not found */
	else {
		index[++counter] = -1; /* mark the end of index[] */
		return index;
	}
}

int main()
{ /* a simple test*/
	int i;
	int *p;

	read_matrix(); /* read triples of a sparse matrix */

	for (i=0; i<= a[0].value; i++) /* print the triples */
		printf("a[%d]: %d, %d, %d \n", i, a[i].row, a[i].col, a[i].value);
	printf("\n");

	print_matrix(); /* print the sparse matrix as a matrix */

/** find 2 from the matrix **/
	if (p = search(2)) { /* if found */
		do {
			i = *p;
			printf("<%d, %d> = 2 \n", a[i].row, a[i].col);
			i = *(++p);
		} while(i != -1); /* print all triples with value == 2 */
	}
	else printf("2 is not found.\n");

	return 0;
}






