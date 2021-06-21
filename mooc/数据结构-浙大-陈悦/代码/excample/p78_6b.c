/* p.78 #6 (b) */

#include <stdio.h>

#define MAX_SIZE 100
#define MAX_TERMS 10000
#define COMPARE(x, y) (((x) < (y))? -1: ((x) == (y))? 0:1)

int add_matrices(int row, int col, 
				  int A_bits[][MAX_SIZE], int A_value[],
				  int B_bits[][MAX_SIZE], int B_value[],
				  int D_bits[][MAX_SIZE], int D_value[])
{/* D = A + B */
	int i, j;
	int Ai=0, Bi=0, Di=0; /* positions of the current entries in value[] */

	if (!row || !col) {
		return -1; /* zero matrix */
	}
	for (i=0; i<row; i++) 
		for (j=0; j<col; j++) 
			switch(COMPARE(A_bits[i][j], B_bits[i][j])) {
			case -1: /* a[i][j]==0 and b[i][j]!=0 */
				D_bits[i][j] = 1;
				D_value[Di++] = B_value[Bi++];
				break;
			case 0: /* either both !=0 or both ==0*/
				if (A_bits[i][j]) { /* if both != 0 */
					if (D_value[Di] = A_value[Ai++]+B_value[Bi++]) { /* if sum != 0 */
						Di++;
						D_bits[i][j] = 1;
					}
					else D_bits[i][j] = 0; /* if sum == 0 */
				}
				else D_bits[i][j] = 0; /* if both == 0 */
				break;
			case 1: /* b[i][j]==0 and a[i][j]!=0 */
				D_bits[i][j] = 1;
				D_value[Di++] = A_value[Ai++];
				break;
			}
	return Di; /* return number of nonzero terms */
}

int main()
{
	int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], D[MAX_SIZE][MAX_SIZE];
	int Av[MAX_TERMS], Bv[MAX_TERMS], Dv[MAX_TERMS];
	int row, col;
	int Ai=-1, Bi=-1;
	int i, j, in;

	/* input numbers of rows and columns */
	do {
		printf("Please enter the number of rows: ");
		scanf("%d", &row);
	} while(row<=0 || row>MAX_SIZE);
	do {
		printf("Please enter the number of columns: ");
		scanf("%d", &col);
	} while(col<=0 || col>MAX_SIZE);

	/* input matrices A and B */
	printf("Please input matrix A:\n");
	for (i=0; i<row; i++)
		for (j=0; j<col; j++) {
			scanf("%d", &in);
			if (in) {
				A[i][j] = 1;
				Av[++Ai] = in;
			}
			else A[i][j] = 0;
		}
	printf("Please input matrix B:\n");
	for (i=0; i<row; i++)
		for (j=0; j<col; j++) {
			scanf("%d", &in);
			if (in) {
				B[i][j] = 1;
				Bv[++Bi] = in;
			}
			else B[i][j] = 0;
		}

	in = add_matrices(row, col, A, Av, B, Bv, D, Dv);

	/* print the result */
	printf("Matrix D = A + B :\n");
	for (i=0; i<row; i++) {
		for (j=0; j<col; j++)
			printf("%d ", D[i][j]);
		printf("\n");
	}
	for (i=0; i<in; i++)
		printf("%d\n", Dv[i]);

	return 0;
}
