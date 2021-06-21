/* p.162 #1 */

#include <stdio.h>
#include <malloc.h>

#define IS_FULL(ptr) (!(ptr))

typedef struct poly_node {
	int coef;
	int expon;
	struct poly_node *next;
};
typedef struct poly_node *poly_pointer;

poly_pointer pread()
{
	poly_pointer ptr = NULL, temp;
	int n, flag = 0;

	do {
		printf("Number of terms = ");
		scanf("%d", &n);
	} while (n<0);
	while (n) {
		temp = (poly_pointer)malloc(sizeof(struct poly_node));
		if (IS_FULL(temp)) {
			printf("Memory FULL.\n");
			exit(1);
		}
		do {
			printf("Enter coef and expon [%d]: ", n);
			scanf("%d %d", &temp->coef, &temp->expon);
			if (!temp->coef) {
				printf("ERROR: coef must not be 0.\n");
				flag = 1;
			}
			else {
				if (ptr && temp->expon <= ptr->expon) {
					printf("Wrong order.\n");
					flag = 1;
				}
				else {
					temp->next = ptr;
					ptr = temp;
					n--;
					flag = 0;
				}
			}
		} while (flag);
	}
	return ptr;
}

main()
{
	poly_pointer ptr = pread();
	poly_pointer temp;

	while (ptr) {
		temp = ptr;
		printf("%d", temp->coef);
		if (temp->expon)
			printf("x^%d ", temp->expon);
		ptr = ptr->next;
		if (ptr)
			printf("+ ");
		else
			printf("= 0\n");
		free(temp);
	}
}
