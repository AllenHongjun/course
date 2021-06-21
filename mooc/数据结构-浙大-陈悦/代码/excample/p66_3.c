/* p.66 #3 */

#include <stdio.h>
#include <math.h>

#define MAX_TERMS 100
typedef struct {
	float coef;
	int expon;
} polynomial; /*prefer sparse polynomial representation*/

polynomial terms[MAX_TERMS];
int avail = 0; /*initialize the available position in terms[]*/

float peval(int starta, int finisha, float x)
{ /* compute a(x) */
	float px = terms[starta].coef;

	while (finisha > starta) {
		px = terms[starta+1].coef 
			+ pow(x, terms[starta].expon-terms[starta+1].expon)*px;
		starta ++;
	}
	return px * pow(x, terms[finisha].expon);
}

int main()
{
	int starta = avail, finisha;
	int i;
	float x;

	/*** input a ***/
	printf("Please enter terms of coefficient and exponent of polynimial A:\n");
	printf("Enter -1 as an exponent to finish input.\n");
	do {
		scanf("%f", &terms[avail].coef);
		scanf("%d", &terms[avail++].expon);
	} while (terms[avail-1].expon >= 0);
	finisha = --avail - 1;

	/*** input x ***/
	printf("Please enter x = ");
	scanf("%f", &x);

	/*** output a(x) ***/
	printf("P(x)= %f\n", peval(starta, finisha, x));

	return 0;
}

