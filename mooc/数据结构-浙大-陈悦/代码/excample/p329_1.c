/* p.329 #1 */

#include<stdio.h>

typedef  enum { FALSE, TRUE }  Boolean;

typedef  struct {
    int  key;
    /* other fields can be defined here */
}record;

Boolean ascending ( int x, int y )
/* used to sort in nondecreasing order */
{
  return ( ( x < y )? TRUE : FALSE ) ;  
}

Boolean descending ( int x, int y )
/* used to sort in nonincreasing order */
{
  return ( ( x > y )? TRUE : FALSE ) ;  
}

void insertion_sort ( record list[], int n, Boolean (*f)() )
{ /* sort list[] in either nondecreasing or nonincreasing order   */
  /* the ordering function is passed in as the parameter f        */
  /* the function call is either insertion_sort(list,n,ascending) */
  /* or insertion_sort(list, n, descending) */

   int i, j;
   record  next;

   for ( i=1; i<n; i++ )
   {  next = list[i];  /* next incoming card */
      for ( j=i-1; j>=0 && (*f)(next.key, list[j].key); j-- )
         list[j+1] = list[j]; 
         /* shift the sorted sublist to make a space for next */
      list[j+1] = next; /* place next at the proper position */
   }
}

int main()
{ /* a simple test without error handling*/
	record list[10];
	int n, i;

	printf("Enter number of records ( < 10 ): ");
	scanf("%d", &n);
	printf("Enter %d records: \n", n);
	for (i=0; i<n; i++)
		scanf("%d", &list[i].key);
	insertion_sort(list, n, ascending);
	printf("Ascending order: ");
	for (i=0; i<n; i++)
		printf("%d ", list[i].key);
	insertion_sort(list, n, descending);
	printf("\nDescending order: ");
	for (i=0; i<n; i++)
		printf("%d ", list[i].key);

	return 0;
}
