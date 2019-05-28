#include "BinaryTree.h"


tree *create_tree() {
	tree *t = (tree *)malloc(sizeof(tree));
	t->root = NULL;
	t->size = 0;
	return t;
}

tree_node *createTreeNode(int data) {
	tree_node *temp = (tree_node*)malloc(sizeof(tree_node));
	temp->left_child = temp->right_child = NULL;
	temp->data = data;
	return temp;
}

bool is_tree_empty(tree *t) {
	return t->size == 0;
}

// Insert new values all ordered by value size automatically
void insert_to_tree(tree *t, int data) {
	tree_node *temp = createTreeNode(data);
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
// 1 ordered from small. 2 big to small. 3 root first then rest. 4 only root
void display_tree(tree_node *tempRoot, enum PrintMode_Tree x) {
	if (tempRoot == NULL) {
		return;
	}

	switch (x) {
	case 1:
#pragma region Ordered from smallest to biggest
		display_tree(tempRoot->left_child, 1);
		printf("%c\t", tempRoot->data);
		display_tree(tempRoot->right_child, 1);
#pragma endregion
		break;
	case 2:
#pragma region Biggest to smallest
		display_tree(tempRoot->right_child, 2);
		printf("%d\t", tempRoot->data);
		display_tree(tempRoot->left_child, 2);
#pragma endregion
		break;

	case 3:
#pragma region root first, then the rest
		printf("%c\t", tempRoot->data);
		display_tree(tempRoot->right_child, 3);
		display_tree(tempRoot->left_child, 3);
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

// insert value to left, if left child already exist, continue down the tree until left child is empty
void insert_left(tree_node *n, int data) {
	if (n->left_child == NULL) {
		n->left_child = createTreeNode(data);
		return;
	}
	insert_left(n->left_child, data);
}

//traverse until empty spot and add to the right
void insert_right(tree_node *n, int data) {
	if (n->right_child == NULL) {
		n->right_child = createTreeNode(data);
		return;
	}
	insert_left(n->right_child, data);
}

// insert new root, if root exist, replace it
void set_root(tree *Tree, int data) {
	if (Tree->root == NULL) {
		Tree->root = createTreeNode(data);
		return;
	}
	tree_node *temp = Tree->root;
	Tree->root = createTreeNode(data);
	Tree->root->left_child = temp->left_child;
	Tree->root->right_child = temp->right_child;
	free(temp);
}

int get_root(tree *Tree) {
	return Tree->root->data;
}

int get_left_child(tree_node *n) {
	return n->left_child->data;
}

int get_right_child(tree_node *n) {
	return n->right_child->data;
}
