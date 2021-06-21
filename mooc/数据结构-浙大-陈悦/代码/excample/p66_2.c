/* p.66 #2 */

#include <stdio.h>

#define COMPARE(x, y) (((x) < (y))? -1: ((x) == (y))? 0:1)
#define MAX_TERMS 100

typedef struct {
	float coef;
	int expon;
} polynomial; /*prefer sparse polynomial representation*/

polynomial terms[MAX_TERMS];
int avail = 0; /*initialize the available position in terms[]*/

void attach (float coefficient, int exponent)
{ /*attach one term to the current polynomial*/
	if (avail >= MAX_TERMS) {
		printf("ERROR: Overflow.\n");
		exit(1);  /* I know it's not good :( */
	}
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}

void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd)
{ /* d = a + b -- copied from textbook */
	float coefficient;
	*startd = avail;
	while (starta <= finisha && startb <= finishb)
		switch (COMPARE(terms[starta].expon, terms[startb].expon)) {
		  case -1:
			  attach(terms[startb].coef, terms[startb].expon);
			  startb++;
			  break;
		  case 0:
			  coefficient = terms[starta].coef + terms[startb].coef;
			  if (coefficient)
				  attach(coefficient, terms[starta].expon);
			  starta++;
			  startb++;
			  break;
		  case 1:
			  attach(terms[starta].coef, terms[starta].expon);
			  starta++;
		}
	for (; starta <= finisha; starta++)
		attach(terms[starta].coef, terms[starta].expon);
	for (; startb <= finishb; startb++)
		attach(terms[startb].coef, terms[startb].expon);
	*finishd = avail - 1;
}

void SingleMult(int starta, int finisha, float coefficient, int exponent, 
				int *startd, int *finishd)
{ /*  d = (coef*x^expon) * a  */
	*startd = avail;
	while (starta <= finisha) {
		terms[avail].coef = terms[starta].coef * coefficient;
		terms[avail++].expon = terms[starta++].expon + exponent;
	}
	*finishd = avail - 1;
}

void Move(int *starta, int *finisha, int position)
{ /* move a to position */
	int temp = position;
	int s = *starta;
	int f = *finisha;

	while (s <= f) {
		terms[position].coef = terms[s].coef;
		terms[position++].expon = terms[s++].expon;
	}
	*starta = temp;
	*finisha = position - 1;
}

void pmult(int starta, int finisha, int startb, int finishb, int *startd, int *finishd)
{ /*  d = a * b  */
	int sd, fd, st1, ft1, st2, ft2;
	int i;

	*startd = avail;

	/*  d(x)=sum of {a[i].coef*x^(a[i].expon)*b(x)}  */
	SingleMult(startb, finishb, terms[starta].coef, terms[starta].expon, &sd, &fd);
	for (i = starta+1; i<=finisha; i++) {
		SingleMult(startb, finishb, terms[i].coef, terms[i].expon, &st1, &ft1);
		padd(sd, fd, st1, ft1, &st2, &ft2);
		Move(&st2, &ft2, sd); /*make sure that d is saved next to a and b*/
		sd = st2;
		fd = ft2;
		avail = fd + 1;
	}
	*finishd = fd;
}

int main()
{
	int starta = avail, startb, startd;
	int finisha, finishb, finishd;
	int i;

/*** read a ***/
	printf("Please enter terms of coefficient and exponent of polynimial A:\n");
	printf("Enter -1 as an exponent to finish input.\n");
	do {
		scanf("%f", &terms[avail].coef);
		scanf("%d", &terms[avail++].expon);
	} while (terms[avail-1].expon >= 0);
	startb = --avail;
	finisha = startb - 1;

/*** read b ***/
	printf("Please enter terms of coefficient and exponent of polynimial B:\n");
	printf("Enter -1 as an exponent to finish input.\n");
	do {
		scanf("%f", &terms[avail].coef);
		scanf("%d", &terms[avail++].expon);
	} while (terms[avail-1].expon >= 0);
	finishb = --avail -1;

	pmult(starta, finisha, startb, finishb, &startd, &finishd);

/*** output d = a * b ***/
	for (i=0; i<avail; i++)
		printf("%f  %d\n", terms[i].coef, terms[i].expon);

	return 0;
}
