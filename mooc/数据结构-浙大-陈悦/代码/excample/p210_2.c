/* p.210 #2 */

#include <stdio.h>
#include <malloc.h>

#define IS_FULL(ptr) (!(ptr))

typedef struct node *tree_pointer;
typedef struct node {
	int data;
	tree_pointer left_child, right_child;
};

tree_pointer new_node()
{
	tree_pointer temp;

	temp = (tree_pointer)malloc(sizeof(struct node));
	if (IS_FULL(temp)) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	return temp;
}

void swap_tree(tree_pointer root)
{ /* swap left and right -- the tree is changed */
	tree_pointer temp;

	if (root) {
		temp = root->left_child;
		root->left_child = root->right_child;
		root->right_child = temp;
		swap_tree(root->right_child);
		swap_tree(root->left_child);
	}
}

tree_pointer swap_tree2(tree_pointer root)
{ /* swap left and right -- a new tree is created */
	tree_pointer temp;

	if (root) {
		temp = new_node();
		temp->left_child = swap_tree2(root->right_child);
		temp->right_child = swap_tree2(root->left_child);
		temp->data = root->data;
		return temp;
	}
	else
		return NULL;
}

void print_tree(tree_pointer root)
{ /* preorder traversal printing the tree */
	if (!root) return;
	printf("%d\n", root->data);
	printf("left: ");
	print_tree(root->left_child);
	printf("right: ");
	print_tree(root->right_child);
}

void free_tree(tree_pointer root)
{
	if (!root) return;
	free_tree(root->left_child);
	free_tree(root->right_child);
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

	print_tree(root);
	swap_tree(root);
	print_tree(root);
//	temp = swap_tree2(root);
//	print_tree(temp);

	free_tree(root);
//	free_tree(temp);

	return 0;
}
