/* p.177 #1 */

#include <stdio.h>
#include <malloc.h>

/* copy from book */
#define MAX_SIZE 50
#define IS_FULL(ptr) (!(ptr))
#define COMPARE(x, y) (((x) < (y))? -1: ((x) == (y))? 0:1)

typedef enum {head, entry} tagfield;
typedef struct matrix_node *matrix_pointer;
typedef struct entry_node {
	int row;
	int col;
	int value;
};
typedef struct matrix_node {
	matrix_pointer down;
	matrix_pointer right;
	tagfield tag;
	union {
		matrix_pointer next;
		struct entry_node entry;
	} u;
};
matrix_pointer hdnode[MAX_SIZE];

matrix_pointer new_node()
{ /* malloc a new node */

	matrix_pointer temp;

	temp = (matrix_pointer)malloc(sizeof(struct matrix_node));
	if (IS_FULL(temp)) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	return temp;
}

matrix_pointer mread()
{	/* copy from book -- it's not friendly and robust, but don't blame me*/

	int num_rows, num_cols, num_terms, num_heads;
	int row, col, value, current_row;
	int i;
	matrix_pointer temp, last, node;

	printf("Enter the number of rows, columns and number of nonzero terms: ");
	scanf("%d%d%d", &num_rows, &num_cols, &num_terms);
	num_heads = (num_cols > num_rows) ? num_cols : num_rows;
	node = new_node();
	node->tag = entry;
	node->u.entry.row = num_rows;
	node->u.entry.col = num_cols;

	if (!num_heads) node->right = node;
	else {
		for (i=0; i<num_heads; i++) {
			temp = new_node();
			hdnode[i] = temp;  hdnode[i]->tag = head;
			hdnode[i]->right = temp;  hdnode[i]->u.next = temp;
		}
		current_row = 0;
		last = hdnode[0];

		for (i=0; i<num_terms; i++) {
			printf("Enter row, column and value: ");
			scanf("%d%d%d", &row, &col, &value);
			if (row > current_row) {
				last->right = hdnode[current_row];
				current_row = row;
				last = hdnode[row];
			}
			temp = new_node();
			temp->tag = entry;
			temp->u.entry.row = row;
			temp->u.entry.col = col;
			temp->u.entry.value = value;
			last->right = temp; last = temp;
			hdnode[col]->u.next->down = temp;
			hdnode[col]->u.next = temp;
		}
		last->right = hdnode[current_row];
		for (i=0; i<num_cols; i++)
			hdnode[i]->u.next->down = hdnode[i];
		for (i=0; i<num_heads-1; i++)
			hdnode[i]->u.next = hdnode[i+1];
		hdnode[num_heads-1]->u.next = node;
		node->right = hdnode[0];
	}
	return node;
}

void mwrite(matrix_pointer node)
{	/* Modified mwrite. */
	/* Instead of printing the triples, this one prints the matrix. */
	/* To make sure there is no 0 node, the original 0's are printed*/
	/* as blanks on screen. */

	int row, col, current_col;
	int i, j;
	matrix_pointer temp, head = node->right; 
	/* head points to the head node of the 1st row */

	row = node->u.entry.row;  col = node->u.entry.col;
	/* Print the sizes of the matrix */
	printf("\n num_rows = %d, num_cols = %d\n\n",row, col);
	/* Start printing ... */
	printf("The matrix is:\n\n");
	
	for (i=0; i<row; i++) {
		temp = head->right; /* read in one entry from the i-th row*/
		if (temp != head) {
			current_col = temp->u.entry.col;
			for (j=0; j<col; j++) { /* for each entry of the matrix */
				if (j != current_col)
					printf("     "); /* if it's a zero entry, print blank */
				else { /* else print the nonzero value */
					printf("%5d", temp->u.entry.value);
					temp = temp->right; /* continue to print the next entry */
					if (temp != head)
						current_col = temp->u.entry.col;
				} /* end-else */
			} /* end-j-loop */
		} /* end if-row is not finished */
		printf("\n"); /* ready to print the next row */
		head = head->u.next;  /* next row */
	} /* end i-loop */
}

void attach(int row, int col, int value, 
			matrix_pointer *t, matrix_pointer *h)
{	/* create a new entry node with given row, col, and value */
	/* then link it to the proper position of the matrix */
	/* t points to the last entry in the row */
	/* h is the head node pointer in the col */

	matrix_pointer temp;

	/* create the entry node */
	temp = new_node();
	temp->tag = entry;
	temp->u.entry.row = row;
	temp->u.entry.col = col;
	temp->u.entry.value = value;
	/* attach it next to t in the row */
	(*t)->right = temp; *t = temp;
	/* link it into the column */
	(*h)->u.next->down = temp;
	(*h)->u.next = temp;
}

matrix_pointer madd(matrix_pointer a, matrix_pointer b)
{	/* return d = a + b */

	int num_rows, num_cols, num_heads, sum;
	int i, num_values = 0; /* number of nonzero terms in d */
	matrix_pointer d;
	matrix_pointer ahead = a->right; /* the first head node of a */
	matrix_pointer bhead = b->right; /* the first head node of b */
	matrix_pointer tempa, tempb, tempd;

	num_rows = a->u.entry.row; num_cols = a->u.entry.col;
	/* check if the call is legal */
	if ((num_rows!=b->u.entry.row) || (num_cols!=b->u.entry.col)) {
		fprintf(stderr, "Sizes don't match.\n");
		return NULL;
	}
	/* initialize d, similar to that of mread */
	num_heads = (num_cols > num_rows) ? num_cols : num_rows;
	d = new_node();  d->tag = entry;
	d->u.entry.row = num_rows;  d->u.entry.col = num_cols;

	if (!num_heads) d->right = d; 
	else {
		for (i=0; i<num_heads; i++) {
			tempd = new_node();
			hdnode[i] = tempd;  hdnode[i]->tag = head;
			hdnode[i]->right = tempd;  hdnode[i]->u.next = tempd;
		}
		for (i=0; i<num_rows; i++) {
			/* start from the 1st entries in i-th row of a and b */
			tempa = ahead->right;  tempb = bhead->right;
			tempd = hdnode[i]->right; /* the last entry in the current row */

			while((tempa!=ahead) && (tempb!=bhead)) 
				switch(COMPARE(tempa->u.entry.col, tempb->u.entry.col)) {
				case 1: /* col_a > col_b */
					attach(tempb->u.entry.row, tempb->u.entry.col,
						tempb->u.entry.value, &tempd, 
						&hdnode[i]);  /* attach entry_b to d */
					num_values ++;
					tempb = tempb->right; /* next b entry */
					break;
				case 0: /* col_a == col_b */
					sum = tempa->u.entry.value + tempb->u.entry.value;
					if (sum) { /* if the sum is nonzero, attach to d */
						attach(tempb->u.entry.row, tempb->u.entry.col,
							sum, &tempd, &hdnode[tempb->u.entry.col]);
						num_values ++;
					}
					/* then move on no matter what */
					tempa = tempa->right;  tempb = tempb->right;
					break;
				case -1: /* col_a < col_b */
					attach(tempa->u.entry.row, tempa->u.entry.col,
						tempa->u.entry.value, &tempd, 
						&hdnode[i]); /* attach entry_a to d */
					num_values ++;
					tempa = tempa->right; /* next a entry */
					break;
				}
			/* which ever row is longer, attach the rest to d */
			for (; tempa!=ahead; tempa=tempa->right) {
				attach(tempa->u.entry.row, tempa->u.entry.col,
						tempa->u.entry.value, &tempd, 
						&hdnode[tempa->u.entry.col]);
				num_values ++;
			}
			for (; tempb!=bhead; tempb=tempb->right) {
				attach(tempb->u.entry.row, tempb->u.entry.col,
						tempb->u.entry.value, &tempd, 
						&hdnode[tempb->u.entry.col]);
				num_values ++;
			}
			tempd->right = hdnode[i]; /* close the row */
			ahead = ahead->u.next; bhead = bhead->u.next; /* next row */
		} /* end i-loop */
		for (i=0; i<num_cols; i++) /* close columns of d */
			hdnode[i]->u.next->down = hdnode[i];
		for (i=0; i<num_heads-1; i++) /* link head nodes of d */
			hdnode[i]->u.next = hdnode[i+1];
		hdnode[num_heads-1]->u.next = d;
		d->right = hdnode[0]; /* finally link the 1st node in */
		d->u.entry.value = num_values; /* don't forget this */
	} /* end else for a nonzero matrix */
	return d;
}

main()
{
	matrix_pointer a, b, d;

	a = mread();
	b = mread();
	d = madd(a, b);
	mwrite(a);
	mwrite(b);
	if (d)
		mwrite(d);
}