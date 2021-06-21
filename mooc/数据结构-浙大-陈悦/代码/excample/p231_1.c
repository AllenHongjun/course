/* p.231 #1 */

#include <stdio.h>
#include <malloc.h>

#define IS_FULL(ptr) (!(ptr))

typedef enum {FALSE, TRUE} boolean;

typedef struct node *tree_pointer;
typedef struct node {
	int data;
	int count;
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

void free_tree(tree_pointer root)
{	/* recursive postorder free-call */
	if (!root) return;
	free_tree(root->left_child);
	free_tree(root->right_child);
	printf("%d is free\n", root->data);
	free(root);
}

void print_tree(tree_pointer root)
{
	if (!root) return;
	printf("(%d, %d)\n", root->data, root->count);
	printf("goto left\n");
	print_tree(root->left_child);
	printf("goto right\n");
	print_tree(root->right_child);
}

tree_pointer modified_search (tree_pointer tree, int key)
{ /* search for the key in tree */
	while (tree) {
		if (key == tree->data) 
			return tree; /* found */
		if ((key<tree->data) && (tree->left_child))
			tree = tree->left_child; /* search in left subtree */
		else
			if ((key>tree->data) && (tree->right_child))
				tree = tree->right_child; /* search in right subtree */
			else
				return tree; /* not found -- return the last node encountered */
	}
	return NULL; /* empty tree */
}

void modified_insert (tree_pointer *tree, int key)
{
	tree_pointer ptr;
	tree_pointer temp = modified_search(*tree, key);
/*	if (key is found)  return the node with key
    else  return the last node encountered */

	if (temp && temp->data == key) /* key is found */
		temp->count ++;
	else { /* create a new node and insert it */
		ptr = new_node();
		ptr->data = key;
		ptr->count = 0; /* Don't forget to initialize the counter */
		ptr->left_child = ptr->right_child = NULL;
		if (temp)
			if (key < temp->data)
				temp->left_child = ptr;
			else
				temp->right_child = ptr;
		else
			*tree = ptr;
	}
}

void delete_leaf (tree_pointer *parent, tree_pointer leaf)
{ /* must know leaf's parent */
	if ((*parent)->left_child == leaf)
		(*parent)->left_child = NULL;
	else
		(*parent)->right_child = NULL;
	free(leaf);
}

void delete_left_max(tree_pointer *node)
{
	tree_pointer parent = *node;
	tree_pointer child = parent->left_child;

	while (child->right_child) {
		parent = child;
		child = child->right_child;
	}
	(*node)->data = child->data;
	(*node)->count = child->count;
	if (parent->left_child == child)
		parent->left_child = child->left_child;
	else
		parent->right_child = child->left_child;
	free(child);
}

void delete_right_min(tree_pointer *node)
{
	tree_pointer parent = *node;
	tree_pointer child = parent->right_child;

	while (child->left_child) {
		parent = child;
		child = child->left_child;
	}
	(*node)->data = child->data;
	(*node)->count = child->count;
	if (parent->right_child == child)
		parent->right_child = child->right_child;
	else
		parent->left_child = child->right_child;
	free(child);
}

boolean modified_delete (tree_pointer *tree, int key)
{
	tree_pointer temp = *tree;
	tree_pointer parent;

	if (!temp) return FALSE; /* empty tree */

	if ((!temp->left_child)&&(!temp->right_child)
		&&(temp->data == key)&&(!temp->count)) {
		*tree = NULL;
		free(temp);
		return TRUE;
	} /* if tree has one node containing key */
	while(key != temp->data) { /* find key and its parent */
		if ((key<temp->data) && (temp->left_child)) {
			parent = temp;
			temp = temp->left_child;
		}
		else
			if ((key>temp->data) && (temp->right_child)) {
				parent = temp;
				temp = temp->right_child;
			}
			else
				return FALSE; /* not found */
	}
	if (temp->count) {
		temp->count --;
		return TRUE; /* if find more than one key */
	}
	/* if must delete the node */
	if ((!temp->left_child) && (!temp->right_child)) 
		delete_leaf(&parent, temp);
	else {
		if (temp->left_child)
			delete_left_max(&temp);
		else
			delete_right_min(&temp);
	}
	return TRUE;
}

int main()
{ /* a simple test */
	tree_pointer root = NULL;
	char in;
	int key;

	do {
		printf("1=insert; 2=delete; 3=print.\n");
		printf("Hit any other key to quit.\n");
		scanf("%c", &in); getchar(); /* get input + [Enter] */
		switch (in) {
		case '1':
			printf("Insert Key = ");
			scanf("%d", &key); getchar();
			modified_insert(&root, key);
			break;
		case '2':
			printf("Delete Key = ");
			scanf("%d", &key); getchar();
			if (!modified_delete(&root, key))
				fprintf(stderr, "The key %d is not found.\n", key);
			break;
		case '3':
			print_tree(root);
			break;
		default:
			in = '0';
			break;
		}
	} while (in != '0');

	free_tree(root);
	return 0;
}
