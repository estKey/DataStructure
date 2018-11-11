#pragma once
#ifndef LINKEDSTACK_HPP_INCLUDE
#define LINKEDSTACK_HPP_INCLUDE

namespace ls {
#include <stdio.h>
#include <stdlib.h>

	typedef struct Node
	{
		int value;
		Node *next;
	}Node;

	typedef struct Stack
	{
		int size;
		Node *top;
	}Stack;

	int lsUI();
	Stack* initStack(Stack *stack);
	void Push(Stack *stack, int value);
	void Pop(Stack *stack);
	int *Tos(Stack *stack);
	void printStack(Stack * stack);
	int isEmpty(Stack* stack);
}

#endif