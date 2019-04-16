#pragma once

#include "UtilityLibs.h"


#ifndef BINARYTREE_H
#define BINARYTREE_H


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
bool is_tree_empty(tree *t);
void insert_to_tree(tree *t, int data);
void display_tree(tree_node *tempRoot, int displayModeSelection);
void destroy_tree(tree *tempRoot);

#endif