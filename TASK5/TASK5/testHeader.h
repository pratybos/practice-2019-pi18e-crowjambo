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
	printf("Values to be inserted %s %s \n", someValue.question, someValue.answer);
	list_new_insert(someList, someValue);

	tree_values(someList, root->right_child);
	tree_values(someList, root->left_child);
}