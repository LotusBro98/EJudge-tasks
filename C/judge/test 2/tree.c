#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node
{
	Data val;
	struct Node * left;
	struct Node * right;
};

struct Node * tree_add (struct Node * tree, Data x)
{
	struct Node * leaf;

	if (tree != NULL)
	{
		if (x > tree->val)
		{
			leaf = tree_add (tree->right, x); 
			tree->right = leaf;
		} else if (x < tree->val)
		{
			leaf = tree_add (tree->left, x);
			tree->left = leaf;
		}
	} else {
		leaf = malloc (sizeof (struct Node));
		leaf->left = NULL;
		leaf->right = NULL;
		leaf->val = x;
		tree = leaf;
	}

	return tree;
}

void tree_print_leaves (struct Node * tree)
{
	if (tree != NULL)
	{
		if (tree->left == NULL && tree->right == NULL)
		{
			printf ("%d ", tree->val);
		} else {
			tree_print_leaves (tree->left);
			tree_print_leaves (tree->right);
		}
	}
}

int tree_count_leaves ( struct Node * tree )
{
	if (tree != NULL)
	{
		if (tree->left == NULL && tree->right == NULL)
		{
			return 1;
		} else {
			return tree_count_leaves( tree->left ) + tree_count_leaves( tree->right );
		}
	} else 
		return 0;
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

	printf( "%d\n", tree_count_leaves( tree ) );

	tree_destroy (tree);
	return 0;
}
