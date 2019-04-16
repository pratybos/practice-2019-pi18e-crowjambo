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

void insert_to_tree(tree *t, int data) {
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

// Pay attention that you have to send in tree->root !!! else it works,but crashes
void display_tree(tree_node *tempRoot, int displayModeSelection) {
	if (tempRoot == NULL) {
		return;
	}

	switch (displayModeSelection) {
	case 1:
		#pragma region Ordered from smallest to biggest
		display_tree(tempRoot->left_child,1);
		printf("%d\t", tempRoot->data);
		display_tree(tempRoot->right_child,1);
		#pragma endregion
		break;
	case 2:
		#pragma region Biggest to smallest
		display_tree(tempRoot->right_child,2);
		printf("%d\t", tempRoot->data);
		display_tree(tempRoot->left_child,2);
		#pragma endregion
		break;

	case 3:
		#pragma region root first, then the rest
		printf("%d\t", tempRoot->data);
		display_tree(tempRoot->right_child,3);
		display_tree(tempRoot->left_child,3);
		#pragma endregion
		break;

	case 4:
		// only root
		printf("%d\t", tempRoot->data);
		break;

	default:
		return;
	}
}

// recursive traversal, but now freeing up nodes
void destroy_tree(tree_node *tempRoot) {
	if (tempRoot == NULL) {
		return;
	}
	destroy_tree(tempRoot->left_child);
	destroy_tree(tempRoot->right_child);
	free(tempRoot);
}