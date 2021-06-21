/* p.303 #8 */

#include <stdio.h>
#include <malloc.h>

#define IS_FULL(ptr) (!(ptr))

#define MAX_VERTICES 6
#define MAX_NO 1000

int **Array2D (int row, int col)
{ /* create a 2D array */
	int *x, **y;
	int i;

	x = (int *)calloc(row*col, sizeof(int));
	y = (int **)calloc(row, sizeof(int *));
	if (IS_FULL(x) || IS_FULL(y)) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	for (i=0; i<row; i++)
		y[i] = &x[col*i];
	return y;
}

void free_2DArray (int **a)
{
	free(a[0]);
	free(a);
}

void print_path (int **path, int i, int j)
{ /* print vertices on the path between i and j (i and j are not printed) */
	if (path[i][j] != -1) { /* if there are vertices in between */
		print_path(path, i, path[i][j]); /* print the path from i to k */
		printf("%d -> ", path[i][j]); /* print k */
		print_path(path, path[i][j], j); /* print path from k to j */
	}
}

void modified_allcosts (int cost[][MAX_VERTICES], int distance[][MAX_VERTICES], int n)
{
	int **path; /* Use another array, path[ ][ ], to record the vertex */
	            /* on the path between a source and a destination. */
	int i, j, k;

	path = Array2D(n, n); /* calloc a 2D array of size n by n */
	for (i=0; i<n; i++)
		for (j=0; j<n; j++) {
			distance[i][j] = cost[i][j]; /* initialize distance */
			path[i][j] = -1; /* when there is no vertex between i and j */
		}
	for (k=0; k<n; k++) /* for each vertex k */
		for (i=0; i<n; i++) /* for each pair of vertices i and j */
			for (j=0; j<n; j++)
				if (distance[i][k]+distance[k][j] < distance[i][j]) {
					distance[i][j] = distance[i][k] + distance[k][j];
					path[i][j] = k; /* the path will be from i to k and then from k to j */
				}
	for (i=0; i<n; i++) /* for each pair of vertices i and j */
		for (j=0; j<n; j++)
			if (distance[i][j] >= MAX_NO)
				printf("No path from %d to %d\n", i, j);
			else {
				printf("%d -> ", i);
				print_path(path, i, j); /* print the vertices between i and j */
				printf("%d.  Distance = %d\n", j, distance[i][j]);
			}
	free_2DArray(path);
}

int main()
{ /* a simple test */
	int cost[][MAX_VERTICES] = 
	{{	0,		50,		10,	MAX_NO,		45,	MAX_NO},
	{MAX_NO,	0,		15,	MAX_NO,		10,	MAX_NO},
	{	20,  MAX_NO,	 0,		15, MAX_NO,	MAX_NO},
	{MAX_NO,	20,	MAX_NO,		0,		35,	MAX_NO},
	{MAX_NO,MAX_NO,		30,	MAX_NO,		0,	MAX_NO},
	{MAX_NO,MAX_NO,	MAX_NO,		3,	MAX_NO,		0}};
	int distance[MAX_VERTICES][MAX_VERTICES];
	int n = 6;

	modified_allcosts(cost, distance, n);

	return 0;
}
