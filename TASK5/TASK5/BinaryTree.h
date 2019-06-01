#pragma once
#include "UtilityLibs.h"

#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct {
	char question[100];
	char answer[20];
}data;

enum DisplayMode_Tree {
	InOrder = 1,
	ReverseOrder = 2,
	RootFirst = 3,
	OnlyRoot = 4
};

struct tree_node {
	data data;
	struct tree_node *left_child;
	struct tree_node *right_child;
};
typedef struct tree_node tree_node;

struct tree {
	int size;
	tree_node *root;
};
typedef struct tree tree;


// FUNCTIONS
tree *create_tree();
bool is_tree_empty(tree *t);
void destroy_tree(tree_node *tempRoot);
data *tree_data_create(char *question, char *answer);


tree_node *createTreeNode(char *question, char *answer);
void destroy_tree(tree_node *tempRoot);
void insert_left(tree_node *n, char *question, char *answer);
void insert_right(tree_node *n, char *question, char *answer);
void set_root(tree *Tree, char *question, char *answer);

void display_tree(tree_node *tempRoot, enum PrintMode_Tree x);

//void tree_values(list *someList, tree_node *root);

#endif