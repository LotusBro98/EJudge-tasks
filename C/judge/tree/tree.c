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

void tree_print (struct Node * tree)
{
	if (tree != NULL)
	{
		tree_print(tree->left);
		printf("%d ", tree->val);
		tree_print(tree->right);
	}
}

int tree_height (struct Node * tree)
{
	int left, right;
	if (tree != NULL)
	{
		left = tree_height (tree->left);
		right = tree_height (tree->right);
		return (left > right ? left : right) + 1;
	} else return 0;
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

int tree_height_balance (struct Node * tree)
{
	int left, right;
	int dh;
	if (tree != NULL)
	{
		left = tree_height_balance (tree->left);
		right = tree_height_balance (tree->right);
		dh = left - right;
		if (left != -1 && right != -1 && dh <= 1 && dh >= -1)
		{
			return (left > right ? left : right) + 1;
		} else return -1;
	} else return 0;
}

int tree_is_balanced (struct Node * tree)
{
	int height = tree_height_balance (tree);
	return (height != -1);
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

	if (tree_is_balanced (tree))
	{
		printf ("YES\n");
	} else 
	{
		printf ("NO\n");
	}
	tree_destroy (tree);
	return 0;
}
