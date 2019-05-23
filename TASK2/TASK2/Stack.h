#pragma once

#include "UtilityLibs.h"
#include "BinaryTree.h"

#ifndef STACK_H
#define STACK_H

// stacks for trees
struct stack_node_for_trees {
	tree_node *data;
	struct stack_node_for_trees *next;
};
typedef struct stack_node_for_trees stack_node_for_trees;

struct stack_for_trees {
	stack_node_for_trees *top;
	int size;
};
typedef struct stack_for_trees stack_for_trees;

//

struct stack_node {
	int data;
	struct stack_node *next;
};
typedef struct stack_node stack_node;

struct stack {
	stack_node *top;
	int size;
};
typedef struct stack stack;


// FUNCTIONS
stack * create_stack();
bool is_stack_empty(stack *s);
void push_stack(stack *s, int data);
int pop_stack(stack *s);
int peek_stack(stack *s);
void display_stack(stack *s);
void destroy_stack(stack *s);
int StackCalculation_Postfix(char* exp, stack* s);

//functions for trees

stack_for_trees * create_stack_tree();
void push_stack_tree(stack_for_trees *s, tree_node *data);
tree_node * pop_stack_tree(stack_for_trees *s);
tree_node * peek_stack_tree(stack_for_trees *s);
bool is_stack_empty_tree(stack_for_trees *s);

#endif