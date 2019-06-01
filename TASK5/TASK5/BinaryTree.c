#include "BinaryTree.h"


data *tree_data_create(char *question, char *answer) {
	data *temp = (data *)malloc(sizeof(data));
	strcpy_s(temp->question, 100, question);
	strcpy_s(temp->answer, 20, answer);
	return temp;
}

tree *create_tree() {
	tree *t = (tree *)malloc(sizeof(tree));
	t->root = NULL;
	t->size = 0;
	return t;
}

tree_node *createTreeNode(char *question, char *answer) {
	tree_node *temp = (tree_node*)malloc(sizeof(tree_node));
	temp->left_child = temp->right_child = NULL;
	strcpy_s(temp->data.question, 100, question);
	strcpy_s(temp->data.answer, 20, answer);
	return temp;
}

bool is_tree_empty(tree *t) {
	return t->size == 0;
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
void insert_left(tree_node *n, char *question, char *answer) {
	if (n->left_child == NULL) {
		n->left_child = createTreeNode(question, answer);
		return;
	}
	insert_left(n->left_child, question,answer);
}

//traverse until empty spot and add to the right
void insert_right(tree_node *n, char *question, char *answer) {
	if (n->right_child == NULL) {
		n->right_child = createTreeNode(question, answer);
		return;
	}
	insert_left(n->right_child, question,answer);
}

// insert new root, if root exist, replace it
void set_root(tree *Tree, char *question, char *answer) {
	if (Tree->root == NULL) {
		Tree->root = createTreeNode(question,answer);
		return;
	}
	tree_node *temp = Tree->root;
	Tree->root = createTreeNode(question, answer);
	Tree->root->left_child = temp->left_child;
	Tree->root->right_child = temp->right_child;
	free(temp);
}

//void tree_values(list *someList, tree_node *root) {
//		if (root == NULL) {
//		return;
//	}
//	//list_node *temp = (list_node *)malloc(sizeof(list_node));
//	//temp->tree_node_data->data = tempRoot->data;
//	//temp->tree_node_data->left_child = tempRoot->left_child;
//	//temp->tree_node_data->right_child = tempRoot->right_child;
//
//
//	testStruct someValue;
//	strcpy_s(someValue.question, 100, root->data.question);
//	strcpy_s(someValue.answer, 20, root->data.answer);
//	list_new_insert(someList, someValue);
//
//	tree_values(root->right_child,someList);
//	tree_values(root->left_child, someList);
//}

////return someshit?
//void get_tree_Testing(tree_node *tempRoot, list *tempList) {
//	if (tempRoot == NULL) {
//		return;
//	}
//	//list_node *temp = (list_node *)malloc(sizeof(list_node));
//	//temp->tree_node_data->data = tempRoot->data;
//	//temp->tree_node_data->left_child = tempRoot->left_child;
//	//temp->tree_node_data->right_child = tempRoot->right_child;
//
//
//	testStruct someValue;
//	strcpy_s(someValue.question, 100, tempRoot->data.question);
//	strcpy_s(someValue.answer, 20, tempRoot->data.answer);
//	list_new_insert(tempList, someValue);
//
//	get_tree_values(tempRoot->right_child,tempList);
//	get_tree_values(tempRoot->left_child, tempList);
//
//	//printf("%c\t", tempRoot->data);
//	//get_tree_values(tempRoot->right_child);
//	//get_tree_values(tempRoot->left_child);
//
//	
//}

//data *get_root(tree *Tree) {
//	return Tree->root->data;
//}
//
//data *get_left_child(tree_node *n) {
//	return n->left_child->data;
//}
//
//data *get_right_child(tree_node *n) {
//	return n->right_child->data;
//}

#pragma region Wont work with new DATA struct


// Insert new values all ordered by value size automatically
//void insert_to_tree(tree *t, data *data) {
//	tree_node *temp = createTreeNode(data);
//	// if empty, just become the root
//	if (is_tree_empty(t)) {
//		t->root = temp;
//		t->size++;
//		return;
//	}
//
//	// used for traversing the tree
//	tree_node *temp2 = t->root;
//
//	while (1) {
//		// if new data is smaller than roots left child
//		if (data < temp2->data) {
//			// if roots left child has space take it
//			if (temp2->left_child == NULL) {
//				temp2->left_child = temp;
//				t->size++;
//				return;
//			}
//			// no space - go down the left tree lower
//			else {
//				temp2 = temp2->left_child;
//			}
//		}
//		// new data is bigger than roots data - take right side
//		else if (temp2->data < data) {
//			// if theres space, take it immediately
//			if (temp2->right_child == NULL) {
//				temp2->right_child = temp;
//				t->size++;
//				return;
//			}
//			// no space = traverse further down
//			else {
//				temp2 = temp2->right_child;
//			}
//
//		}
//		// EQUAL, no reason to add equal value
//		else {
//			break;
//		}
//	}
//}

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


#pragma endregion
