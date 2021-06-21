/* p.13 #9 */

#include <stdio.h>

int r_C(int n, int m)
{ /*the recursive version*/

  if (m!=0 && n>m)
    return r_C(n-1, m) + r_C(n-1, m-1) ;
  else 
	return 1;
}

int i_C(int n, int m)
{ /*the iterative version*/

  int i;
  int bc1 = 1, bc2 = 1;
  /*simplify the formula first*/
  for (i=0; i<n-m; i++)
  {	  bc1 *= (n-i);  /*n(n-1)...(m+1)*/
      bc2 *= (i+1);  /*(n-m)!*/
  }
  return bc1/bc2;
}

void print_C(int n, int m)
{ /*a simple test: print C(n,0) to C(n,m)*/
  if (m > 0)
	  print_C(n, m-1);
  printf("r_C(%d,%d) = %d\n", n, m, r_C(n,m));
  printf("i_C(%d,%d) = %d\n", n, m, i_C(n,m));
}

int main()
{  
   int n, m;

   do {
	   printf("Please input n and m for computing C(n,m).\n");
	   printf(" n = ");
       scanf("%d", &n);
       printf("\n m = ");
       scanf("%d", &m);
   } while (n<0 || m<0); /*check for legal n and m*/

   if (n < m)
	   printf("ERROR: n < m.\n"); /*error handling*/
   else
	   print_C(n, m);
}
