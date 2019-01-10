#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Data{
	int value;
} Data;

typedef struct Node{
	Data data;
	struct	Node * left;
	struct Node * right;
	struct Node * parent;
} Node;

typedef struct Tree{
	Node * root;
	Data * (*insert)(struct Tree *,Data);
	Data * (*search)(struct Tree *bst,Data value);
	void (*sort)(struct Tree *,Data *);
	int (*compare)(struct Tree *t,struct Tree *copy);
	struct Tree *(*clone)(struct Tree *t);
	void (*delete)(struct Tree * bst);
	void (*removeData)(struct Tree * bst,Data value);
} Tree;	

Node * newNode(Data d,Node * parent);
Tree * newTree();

#endif
