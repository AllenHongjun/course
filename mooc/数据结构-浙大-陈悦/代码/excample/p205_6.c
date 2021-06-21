/* p.205 #6 */

#include <stdio.h>
#include <malloc.h>

#define IS_FULL(ptr) (!(ptr))

typedef enum {FALSE, TRUE} boolean;
typedef struct node *tree_pointer;
typedef struct node {
	int data;
	tree_pointer left_child, right_child;
};

typedef struct stack *stack_pointer;
typedef struct stack {
	tree_pointer element;
	boolean ready; /* signal if the tree node can be printed */
	stack_pointer next;
};
stack_pointer top = NULL;

stack_pointer new_node()
{
	stack_pointer temp;

	temp = (stack_pointer)malloc(sizeof(struct stack));
	if (IS_FULL(temp)) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	return temp;
}

void push(stack_pointer *top, tree_pointer item, boolean ready)
{
	stack_pointer temp;

	temp = new_node();
	temp->element = item; temp->ready = ready;
	temp->next = *top;
	*top = temp;
}

stack_pointer pop(stack_pointer *top)
{
	stack_pointer temp = *top;

	if (!temp) {
		fprintf(stderr, "The stack is empty.\n");
		return NULL;
	}
	*top = temp->next;
	return temp;
}

void iter_postorder(tree_pointer root)
{	/* iterative version of postorder traversal */

	stack_pointer temp;

	if (!root) return;
	do {
		for (; root; root=root->left_child)
			/* keep pushing the left path on stack */
			push(&top, root, FALSE);
		if (!top) break;
		/* pop the last node on the left path and check ... */
		temp = pop(&top);
		root = temp->element;
		if (temp->ready) {  /* if it's ready, print it */
			printf("%d ", root->data);	
			root = NULL; /* reset root to skip the first for-loop above */
		}
		else { /* if it's not ready yet */
			push(&top, root, TRUE); /* it will be ready when we come back */
			root = root->right_child; /* visit the right subtree */
		}
	} while ((!root) || (top));
	printf("\n");
}

void free_tree(tree_pointer root)
{	/* recursive postorder free-call */
	if (!root) return;
	free_tree(root->left_child);
	free_tree(root->right_child);
	printf("%d is free\n", root->data);
	free(root);
}

int main()
{ /* a simple test */
	tree_pointer root, temp;

	root = new_node();
	root->data = 1;
	root->left_child = NULL; root->right_child = NULL;
	temp = new_node();
	temp->data = 2;
	temp->left_child = NULL; temp->right_child = NULL;
	root->left_child = temp;
	temp = new_node();
	temp->data = 3;
	temp->left_child = NULL; temp->right_child = NULL;
	root->right_child = temp;
	temp = new_node();
	temp->data = 4;
	temp->left_child = NULL; temp->right_child = NULL;
	root->left_child->left_child = temp;
	temp = new_node();
	temp->data = 5;
	temp->left_child = NULL; temp->right_child = NULL;
	root->left_child->right_child = temp;
	temp = new_node();
	temp->data = 6;
	temp->left_child = NULL; temp->right_child = NULL;
	root->right_child->left_child = temp;
	temp = new_node();
	temp->data = 7;
	temp->left_child = NULL; temp->right_child = NULL;
	root->left_child->left_child->right_child = temp;
	temp = new_node();
	temp->data = 8;
	temp->left_child = NULL; temp->right_child = NULL;
	root->right_child->left_child->right_child = temp;

	iter_postorder(root);
	printf("\n Start free spaces ...\n");
	free_tree(root);

	return 0;
}
