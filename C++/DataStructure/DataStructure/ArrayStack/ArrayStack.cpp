//ArrayStack.cpp
#include "ArrayStack.hpp"
//C style code, sequencial stack

namespace as {

	int asUI()
	{
		Stack *stack = NULL;
		int *top;
		stack = initStack(stack, 4);
		Push(stack, 1);
		Push(stack, 2);
		Push(stack, 3);
		Push(stack, 4);
		printStack(stack);
		top = Tos(stack);
		printf("Top of Stack addr: %x\tvalue: %d\n", top, *top);
		Pop(stack);
		printStack(stack);
		top = Tos(stack);
		printf("Top of Stack addr: %x\tvalue: %d\n", top, *top);
		return 0;
	}

	Stack* initStack(Stack *stack, int size)
	{
		stack = (Stack *)malloc(sizeof(Stack));
		stack->stack = (int *)malloc(sizeof(int)*size);
		stack->top = -1;
		return stack;
	}

	void Push(Stack *stack, int value)
	{
		if(stack != NULL)
		{
			if (stack->stack)
			{
				stack->top++;
				stack->stack[stack->top] = value;
			}
		}
	}

	void Pop(Stack *stack)
	{
		if (stack != NULL)
		{
			if (stack->stack)
			{
				stack->top--;
			}
		}
	}
	int *Tos(Stack *stack)
	{
		if (stack->top == -1)
			return NULL;
		else
			return &(stack->stack[stack->top]);
	}

	void printStack(Stack *stack)
	{
		if (stack != NULL)
		{
			if (stack->stack)
			{
				printf("\nStart Printing Array Stack\n");
				int level = stack->top;
				while (level>=0)
				{
					printf("Level: %d value: %d\n", level, stack->stack[level]);
					level--;
				}
			}
		}
	}


}