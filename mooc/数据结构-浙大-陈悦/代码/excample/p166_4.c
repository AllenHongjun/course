/* p.166 #4 */

#include <stdio.h>
#include <malloc.h>

#define IS_FULL(ptr) (!(ptr))

typedef struct poly_node {
	int coef;
	int expon;
	struct poly_node *next;
};
typedef struct poly_node *poly_pointer;

poly_pointer avail = NULL;

poly_pointer get_node()
{
	poly_pointer node;

	if (avail) {
		node = avail;
		avail = avail->next;
	}
	else {
		node = (poly_pointer)malloc(sizeof(struct poly_node));
		if (IS_FULL(node)) {
			printf("Memory FULL.\n");
			exit(1);
		}
	}
	return node;
}

poly_pointer Cpread()
{
	poly_pointer ptr = NULL, temp;
	int n, flag = 0;

	ptr = get_node(); 
	ptr->expon = -1;
	ptr->next = ptr;
	printf("Number of terms = ");
	scanf("%d", &n);
	while (n) {
		temp = get_node();
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
					temp->next = ptr->next;
					ptr->next = temp;
					n--;
					flag = 0;
				}
			}
		} while (flag);
	}
	return ptr;
}

poly_pointer Creverse(poly_pointer ptr)
{
	poly_pointer middle = NULL, lead = ptr, trail;

	do {
		trail = middle;
		middle = lead;
		lead = lead->next;
		middle->next = trail;
	} while (lead != ptr );
	ptr->next = middle;
	return middle;
}

main()
{
	poly_pointer ptr = Cpread();
	poly_pointer temp;

	ptr = Creverse(ptr);
	while (ptr->expon != -1) {
		temp = ptr;
		printf("%d", temp->coef);
		if (temp->expon)
			printf("x^%d ", temp->expon);
		ptr = ptr->next;
		if (ptr->expon != -1)
			printf("+ ");
		else
			printf("= 0\n");
		free(temp);
	}
	free(ptr);
}
