/* p.13 #5 */

#include<stdio.h>

/*************** For User's Modifications ***************/

typedef float INPUT;  /*define your own input type here*/
typedef float OUTPUT; /*define your own output type here*/
#define Max_Size 100  /*max number of distinct inputs*/

OUTPUT f(INPUT x)
{ /*define your own function here*/
	return (OUTPUT)(x*x); /*f(x)=x^2 is the sample function*/
}

/********************************************************/

void Pigeon_hole(INPUT x[], int n)
/* Note: x[i]'s must be distinct. */
{
	int i, j, k = 0;
	int count_out = n;  /*initialize number of outputs*/
    int a[Max_Size], b[Max_Size]; /*for storing indices of x[]*/

	if (!n) return;  /*do nothing if there's no input*/

	for (i=0; i<n-1; i++)
	{   for (j=i+1; j<n; j++)
		{  if (f(x[i])==f(x[j]))
			{  count_out --; /*reduce number of distinct outputs*/
			   a[k] = i; b[k++] = j; /*record this pair of x[]*/
			}
		}
	}
	printf("There are %d distinct inputs and %d distinct outputs.\n", n, count_out);
	if (k > 0) /*if there are pairs of identical outputs, print them*/
		for (i=0; i<k; i++) 
			printf("f(%f) = f(%f)\n", x[a[i]], x[b[i]]);
}

int read_in(INPUT x[])
{   
	int i, j, n;
	int count_in = 0; /*initialize number of distinct inputs*/

	do {
		printf("Please enter the number of inputs, n = ");
		scanf("%d", &n);
	} while (n<0 || n>Max_Size); /*check for legal input*/

	if (!n) return 0; /*no input*/

	printf("Please enter inputs x[n].\n");
	for (i=0; i<n; i++)
	{	scanf("%f", &x[count_in]); /*NOTE: the current input type is float*/
	    for (j=0; j<count_in; j++)
		{	if (x[count_in]==x[j]) /*ignor the identical inputs*/
				count_in--;
		}
		count_in++; /*save one distinct input*/
	}
	return count_in; /*return number of distinct inputs*/
}

int main()
{    
	INPUT x[Max_Size];

	int count_in = read_in(x);

    Pigeon_hole(x, count_in);

	return 0;
}

