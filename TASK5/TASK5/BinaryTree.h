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
	data *data;
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
tree_node *createTreeNode(data *data);
bool is_tree_empty(tree *t);
void destroy_tree(tree_node *tempRoot);
void insert_left(tree_node *n, data *data);
void insert_right(tree_node *n, data *data);
void set_root(tree *Tree, data *data);
data get_root(tree *Tree);
data get_left_child(tree_node *n);
data get_right_child(tree_node *n);
data *tree_data_create(char *question, char *answer);

#endif