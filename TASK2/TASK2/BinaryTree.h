#pragma once

#include "UtilityLibs.h"


#ifndef BINARYTREE_H
#define BINARYTREE_H

enum DisplayMode_Tree {
	InOrder = 1,
	ReverseOrder = 2,
	RootFirst = 3,
	OnlyRoot = 4
};

struct tree_node {
	int data;
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
tree_node *createTreeNode(int data);
bool is_tree_empty(tree *t);
void insert_to_tree(tree *t, int data);
void display_tree(tree_node *tempRoot, enum PrintMode_Tree x);
void destroy_tree(tree_node *tempRoot);
void insert_left(tree_node *n, int data);
void insert_right(tree_node *n, int data);
void set_root(tree *Tree, int data);
int get_root(tree *Tree);
int get_left_child(tree_node *n);
int get_right_child(tree_node *n);

#endif