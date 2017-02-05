#include <stdin.h>
#include <stdlib.h>

struct _Node
{
	int quantity;
	struct _Node older[10];
};

typedef struct _Node Node;

Node putNumber (Node tree, int number)
{
	if (tree == NULL)
	{
		tree = calloc (1, sizeof (Node));
		tree->quantity = 0;
	}

	if (number == 0)
	{
		tree->quantity += 1;
	} else {
		tree->older[number % 10] = putNumber (tree->older[number % 10], number / 10)
	}

	return tree;
}

void printTree(Node tree)
{
	if (tree != NULL)
	{
		int i;
		for (i = 0; i < 10; i++)
		{

			printTree(tree->older[i]);
		}
	}
}
