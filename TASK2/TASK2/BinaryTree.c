#include "BinaryTree.h"


tree *create_tree() {
	tree *t = (tree *)malloc(sizeof(tree));
	t->root = NULL;
	t->size = 0;
	return t;
}

bool is_tree_empty(tree *t) {
	return t->size == 0;
}

void insert_tree(tree *t, int data) {
	tree_node *temp = (tree_node*)malloc(sizeof(tree_node));
	temp->left_child = temp->right_child = NULL;
	temp->data = data;
	// if empty, just become the root
	if (is_tree_empty(t)) {
		t->root = temp;
		t->size++;
		return;
	}

	// used for traversing the tree
	tree_node *temp2 = t->root;

	while (1) {
		// if new data is smaller than roots left child
		if (data < temp2->data) {
			// if roots left child has space take it
			if (temp2->left_child == NULL) {
				temp2->left_child = temp;
				t->size++;
				return;
			}
			// no space - go down the left tree lower
			else {
				temp2 = temp2->left_child;
			}
		}
		// new data is bigger than roots data - take right side
		else if (temp2->data < data) {
			// if theres space, take it immediately
			if (temp2->right_child == NULL) {
				temp2->right_child = temp;
				t->size++;
				return;
			}
			// no space = traverse further down
			else {
				temp2 = temp2->right_child;
			}
	
		}
		// EQUAL, no reason to add equal value
		else {
			break;
		}
	}
}