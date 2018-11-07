#pragma once
#ifndef ARRAYSTACK_HPP_INCLUDE
#define ARRAYSTACK_HPP_INCLUDE

namespace as {
#include <stdio.h>
#include <stdlib.h>

	typedef struct Stack
	{
		int top;
		int *stack;
	}Stack;

	int asUI();
	Stack* initStack(Stack *stack, int size);
	void Push(Stack *stack, int value);
	void Pop(Stack *stack);
	int *Tos(Stack *stack);
	void printStack(Stack * stack);

}

#endif