/* p.91 #4 */

#include <stdio.h>

int strpos1 (char *string, char character)
{ /* find the position of character in string - version 1*/
	int i;

	for (i=0; string[i]!='\0' && string[i]!=character; i++)
		;
	return ((string[i] == character)? i: -1);
}

int strpos2 (char *string, char character)
{/* find the position of character in string - version 2*/
	int i = 0;

	while (string[i])
		if (string[i++] == character)
			return i-1;
	return -1;
}

int main()
{ /* a simple test */
	char string[] = {"abcdefghiabdef"};
	char c = 'a';
	printf("%d\n", strpos1(string, c));

	return 0;
}
