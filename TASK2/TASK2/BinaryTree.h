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








#endif