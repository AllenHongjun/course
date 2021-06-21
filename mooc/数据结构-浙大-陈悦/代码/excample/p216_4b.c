/* p.216 #4 */
/* Function find_parent is added */

#include <stdio.h>
#include <malloc.h>

#define IS_FULL(ptr) (!(ptr))

typedef enum {FALSE, TRUE} boolean;

typedef struct threaded_tree *threaded_pointer;
typedef struct threaded_tree {
	short int left_thread;
	threaded_pointer left_child;
	char data;
	threaded_pointer right_child;
	short int right_thread;
};

threaded_pointer insucc(threaded_pointer tree)
{/* copied from book */
	threaded_pointer temp;

	temp = tree->right_child;
	if (!tree->right_thread)
		while (!temp->left_thread)
			temp = temp->left_child;
	return temp;
}

threaded_pointer find_parent(threaded_pointer node)
{
	threaded_pointer ptr = node;

	/* in case node is a right child of its parent */
	for (; !ptr->left_thread; ptr = ptr->left_child)
		;
	if (ptr->left_child->right_child == node)
		return ptr->left_child;

	/* in case node is a left child of its parent */
	for (ptr=node; !ptr->right_thread; ptr = ptr->right_child)
		;
	if (ptr->right_child->left_child == node)
		return ptr->right_child;
}


threaded_pointer postsucc(threaded_pointer node)
{
	threaded_pointer tparent = find_parent(node); /* find parent of node */

	if ((node == tparent->left_child) &&
		(!tparent->right_thread) &&
		(tparent != tparent->right_child)) 
/*	if  ((node is a left child of parent) && 
         (parent has a right child) && 
		 (parent is not the head node) )
*/
		for (; !tparent->right_thread; tparent = insucc(tparent))
			;
	return tparent;
}

void threaded_postorder(threaded_pointer tree)
{
	threaded_pointer temp = tree;

	temp=insucc(temp);
	if (temp == tree) return; /* if ( it is an empty tree ) return*/
		
	for (; !temp->right_thread; temp=insucc(temp))
		; /* find the first node to be printed*/
	while (temp != tree) { /* the current node is not the head node*/
		printf("%c ", temp->data);
		temp = postsucc(temp);
	}
}

threaded_pointer new_node()
{
	threaded_pointer temp;

	temp = (threaded_pointer)malloc(sizeof(struct threaded_tree));
	if (IS_FULL(temp)) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	return temp;
}

void free_threaded_tree(threaded_pointer tree)
{
	if (!tree->left_thread)
		free_threaded_tree(tree->left_child);
	if ((!tree->right_thread) && (tree->right_child!=tree))
		free_threaded_tree(tree->right_child);
	printf("%c is free\n", tree->data);
	free(tree);
}

int main()
{ /* a simple test */
	threaded_pointer root, temp, parent, previous;

	root = new_node();
	root->data = 'R'; 
	root->left_thread = root->right_thread = FALSE;
	root->left_child = NULL; root->right_child = root;

	temp = new_node();
	root->left_child = temp;

	temp->data = 'a'; 
	temp->left_thread = temp->right_thread = FALSE;
	previous = parent = temp;

	temp = new_node();
	temp->data = 'b'; 
	parent->left_child = temp;
	temp->left_thread = temp->right_thread = FALSE;

	temp = new_node();
	temp->data = 'c'; 
	parent->right_child = temp;
	temp->left_thread = temp->right_thread = FALSE;

	parent = temp;
	temp = new_node();
	temp->data = 'f'; 
	parent->left_child = temp;
	temp->left_thread = temp->right_thread = TRUE;
	temp->left_child = previous;
	temp->right_child = parent;

	temp = new_node();
	temp->data = 'g'; 
	parent->right_child = temp;
	temp->left_thread = temp->right_thread = TRUE;
	temp->left_child = parent;
	temp->right_child = root;

	parent = previous->left_child;
	temp = new_node();
	temp->data = 'd'; 
	parent->left_child = temp;
	temp->left_thread = temp->right_thread = FALSE;

	temp = new_node();
	temp->data = 'e'; 
	parent->right_child = temp;
	temp->left_thread = temp->right_thread = TRUE;
	temp->left_child = parent;
	temp->right_child = previous;

	previous = parent;
	parent = parent->left_child;
	temp = new_node();
	temp->data = 'h'; 
	parent->left_child = temp;
	temp->left_thread = temp->right_thread = TRUE;
	temp->left_child = root;
	temp->right_child = parent;

	temp = new_node();
	temp->data = 'i'; 
	parent->right_child = temp;
	temp->left_thread = temp->right_thread = TRUE;
	temp->left_child = parent;
	temp->right_child = previous;

	threaded_postorder(root);
	/* Answer: h i d e b f g c a */
	free_threaded_tree(root);

	return 0;
}
