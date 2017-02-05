#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct Tree {
	struct Tree* left;
	struct Tree* right;
	int* value;
};

struct Tree* makeNode(struct Tree* left, struct Tree* right) {
	struct Tree* tp = malloc(sizeof(struct Tree));
	tp->left = left;
	tp->right = right;
	tp->value = NULL;
	return tp;
}

struct Tree* makeLeaf(int value) {
	struct Tree* tp = malloc(sizeof(struct Tree));
	tp->left = NULL;
	tp->right = NULL;
	tp->value = malloc(sizeof(int));
	*(tp->value) = value;
	return tp;
}

struct Tree* root;

void printTree(struct Tree* tp) {
	if (tp->value == NULL) {
		printf("(");
		printTree(tp->left);
		printf(" ");
		printTree(tp->right);
		printf(")");
	} else {
		printf("%d", *(tp->value));
	}
}

void destroyTree(struct Tree* tp){
	if (tp != NULL) {
		destroyTree(tp->left);
		destroyTree(tp->right);
		free(tp->value);
		free(tp);
	}
	printTree(root);
	printf("\n");
}

int main(){
	root = makeNode(makeLeaf(10),makeNode(makeLeaf(1),makeLeaf(2)));
	printTree(root);
	printf("\n");
	destroyTree(root);
	return 0;
}
