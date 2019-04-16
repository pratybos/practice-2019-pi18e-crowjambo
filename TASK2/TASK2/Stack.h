#pragma once
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


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

#endif