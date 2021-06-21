/* p.92 #6 */

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

/*** a simple test ***/
char s[MAX_SIZE] = {"abcdefg"};
char t[MAX_SIZE] = {"0123456"};

void strnins(char *s, char *t, int i)
{ /* insert t into s at position i */

	int Ls = strlen(s), Lt;
	int k;

	if (i<0 || i>Ls) {
		fprintf(stderr, "Position is out of bounds \n");
		exit(1);
	} /*error handling -- not friendly, I know *^_^* */

	if (!Ls)
		strcpy(s, t); /* if s is empty, attach t to s */
	else if (Lt = strlen(t)) { /* if t is not empty */
		for (k=Ls-1; k>=i; k--)
			s[k+Lt] = s[k]; /* shift part of s to make space available for t */
		for (k=Lt+i-1; k>=i; k--)
			s[k] = t[k-i]; /* copy t into s */
	}
}

int main()
{
	int i;

	/* a simple test */
	printf("Please enter the position i: ");
	scanf("%d", &i);
	strnins(s, t, i);
	printf("%s\n", s);

	return 0;
}
