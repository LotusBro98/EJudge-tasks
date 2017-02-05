#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node
{
	Data val;
	struct Node * left;
	struct Node * right;
};

struct QNode
{
	struct Node * tree;
	struct QNode * next;
};

struct Queue
{
	struct QNode * first;
	struct QNode * last;
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

void pushQ(struct Queue * q, struct Node * tree)
{
	if (tree != NULL)
	{
		struct QNode * p = malloc (sizeof (struct QNode));
		p->tree = tree;
		p->next = NULL;
		if (q->last != NULL) q->last->next = p;
		q->last = p;
		if (q->first == NULL) q->first = p;
	}
}

struct Node * popQ(struct Queue * q)
{
	struct QNode * p;
	struct Node * tree;

	p = q->first;
	q->first = p->next;
	if (q->first == NULL) q->last = NULL;
	tree = p->tree;
	free(p);
	return tree;
}

int isEmptyQ (struct Queue * q)
{
	return q->first == NULL;
}

void tree_print_by_width (struct Node * tree)
{
	struct Queue q;
	struct Node * node;

	q.first = NULL;
	q.last = NULL;

	pushQ(&q, tree);

	while (!isEmptyQ (&q))
	{
		node = popQ(&q);
		printf("%d ", node->val);
		pushQ(&q, node->left);
		pushQ(&q, node->right);
	}

	printf("\n");
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

	tree_print_by_width (tree);
	tree_destroy (tree);
	return 0;
}
