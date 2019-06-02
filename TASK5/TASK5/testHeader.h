#pragma once
#include "UtilityLibs.h"


void tree_values(list *someList, tree_node *root) {
	if (root == NULL) {
		return;
	}
	//list_node *temp = (list_node *)malloc(sizeof(list_node));
	//temp->tree_node_data->data = tempRoot->data;
	//temp->tree_node_data->left_child = tempRoot->left_child;
	//temp->tree_node_data->right_child = tempRoot->right_child;


	testStruct someValue;
	strcpy_s(someValue.question, 100, root->data.question);
	strcpy_s(someValue.answer, 20, root->data.answer);

	list_new_insert(someList, someValue);

	tree_values(someList, root->right_child);
	tree_values(someList, root->left_child);
}

//populating existing binary tree with values in same way they were extracted
void tree_set_values(tree_node *root,list_node *node) {
	if (root == NULL) {
		//root = createTreeNode(data2.question, data2.answer);
		return;
	}
	//list_node *temp = (list_node *)malloc(sizeof(list_node));
	//temp->tree_node_data->data = tempRoot->data;
	//temp->tree_node_data->left_child = tempRoot->left_child;
	//temp->tree_node_data->right_child = tempRoot->right_child;

	strcpy_s(root->data.question, 100, node->testData.question);
	strcpy_s(root->data.answer, 20, node->testData.answer);

	//traverse further
	tree_set_values(root->right_child, node->next);
	tree_set_values(root->left_child, node->next);


	//list_new_insert(someList, someValue);

	//tree_values(someList, root->right_child);
	//tree_values(someList, root->left_child);
}

void tree_set_empty_nodes(tree_node *root, list_node *node2) {
	if (node2 == NULL) {
		return;
	}

	//static list_node* nodeNode = 
	root = createTreeNode(node2->testData.question,node2->testData.answer);

	//strcpy_s(root->data.question, 100, node2->testData.question);
	//strcpy_s(root->data.answer, 20, node2->testData.answer);

	//traverse further
	tree_set_empty_nodes(root->right_child, node2->next);
	tree_set_empty_nodes(root->left_child, node2->next);



}


