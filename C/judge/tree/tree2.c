#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node
{
	Data val;
	int quantity;
	struct Node * left;
	struct Node * right;
};

struct Node * tree_add (struct Node * tree, Data x)
{
	if (tree == NULL) 
	{
		tree = malloc (sizeof (struct Node));
		tree->left = NULL;
		tree->right = NULL;
		tree->val = x;
		tree->quantity = 1;
	} 
	else if (x > tree->val) 
	{
		tree->right = tree_add (tree->right, x); 
	} 
	else if (x < tree->val) 
	{
		tree->left = tree_add (tree->left, x);
	} 
	else 
	{
		tree->quantity++;
	}

	return tree;
}

void tree_print (struct Node * tree)
{
	if (tree != NULL)
	{
		tree_print(tree->left);
		printf("%d %d\n", tree->val, tree->quantity);
		tree_print(tree->right);
	}
}

void tree_destroy (struct Node * tree)
{
	if (tree != NULL)
	{
		tree_destroy(tree->left);
		tree_destroy(tree->right);
		free(tree);
	}
}

int main()
{
	struct Node * tree = NULL;
	int a;

	while ((scanf ("%d", &a) == 1) && (a != 0))
	{
		tree = tree_add (tree, a);
	}

	tree_print(tree);
	tree_destroy (tree);
	return 0;
}
