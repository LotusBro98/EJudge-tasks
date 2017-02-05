#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ymlNode{
	char* name;
	int level;
	struct ymlNode* next;
	struct ymlNode* previous;
	struct ymlNode* child;
	struct ymlNode* parent;
};

void printSpaceLine(int level){
	for (int i = 0; i<level; i++){
		printf(" ");
	}
}

void printNodeLvl(int level, struct ymlNode* pn){
	if (pn != NULL) {
		printSpaceLine(level);
		printf("%s", pn->name);
		printf(":\n");

		printNodeLvl(level+1,pn->child);
		printNodeLvl(level,pn->next);
	}
}

void printNode(struct ymlNode* pn){
	printNodeLvl(0,pn);
}

struct ymlNode* makeNode(char* name){
	struct ymlNode* node =  malloc(sizeof(struct ymlNode));
	node->name = name;
	node -> level = 0;
	node -> previous = NULL;
	node -> next = NULL;
	node -> parent = NULL;
	node -> child = NULL;
}

void arrangeLevels(struct ymlNode* node){
	if (node != NULL){
		if (node->next != NULL){
			node->next->level = node->level;
			arrangeLevels(node->next);
		}
		if (node->child != NULL){
			node->child->level = node->level + 1;
			arrangeLevels(node->child);
		}
	}
}

void appendNode(struct ymlNode* base, struct ymlNode* node){
	base->next = node;
	node->previous = base;
	arrangeLevels(base);
}

void insertNode(struct ymlNode* parent, struct ymlNode* child){
	parent->child = child;
	child->parent = parent;
	arrangeLevels(parent);
}

struct ymlNode* getLast(struct ymlNode* root){
	struct ymlNode* p;
	if (root != NULL){
		p = root;
		while (p->next != NULL) p = p->next;
		if (p->child != NULL) {
			return getLast(p->child);
		} else {
			return p;
		}
	}
}

void putNode(struct ymlNode* root, struct ymlNode* node){
	struct ymlNode* place = getLast(root);
	if (node->level > place->level) {
		insertNode(place,node);
	} else {
		appendNode(place,node);
	}
}	

struct ymlNode* readNode(FILE *fp, struct ymlNode* root){
	int level = 0;
	char c;
	int n;
	char* name = malloc(sizeof(char)*100);
	struct ymlNode* node;

	if (fscanf(fp, "%c", &c) != 1) return NULL;
	while (c == ' '){
		level++;
		if (fscanf(fp, "%c", &c) != 1) return NULL;
	}
	while (c != ':') {
		n = strlen(name);
		name[n] = c;
		name[n+1] = '\0';
		if ((n = fscanf(fp, "%c", &c)) != 1) return NULL;
	}
	while (c != '\n') {
		if (fscanf(fp, "%c", &c) != 1) return NULL;
	}

	node = makeNode(name);
	node->level = level;
	putNode(root,node);
	return node;
}

struct ymlNode* parseFile(FILE* fp){
	struct ymlNode* root;
	struct ymlNode* node;

	root = makeNode("root");
	while (node != NULL) {
		node = readNode(fp,root);
	}
	if (root->next != NULL) {
		node = root->next;
		free(root);
		return node;
	} else {
		node = root->child;
		free(root);
		return node;
	}
}
