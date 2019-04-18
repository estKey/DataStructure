//Linked Stack
#include "LinkedStack.hpp"

namespace ls {
	int lsUI()
	{
		int *top;
		Stack *stack = NULL;
		stack = initStack(stack);
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

	Stack* initStack(Stack *stack)
	{
		stack = (Stack *)malloc(sizeof(Stack));
		stack->size = 0;
		stack->top = NULL;
		return stack;
	}

	void Push(Stack *stack, int value)
	{
		if (stack != NULL)
		{
			Node *node = (Node *)malloc(sizeof(Stack));
			node->value = value;
			node->next = stack->top;
			stack->top = node;
			stack->size++;
		}
	}

	void Pop(Stack *stack)
	{
		if (stack != NULL)
		{
			if (stack->size > 0)
			{
				Node *delNode;
				delNode = stack->top;
				stack->top = stack->top->next;
				free(delNode);
				stack->size--;
			}
		}

	}

	int *Tos(Stack *stack)
	{
		return &(stack->top->value);
	}

	void printStack(Stack *stack)
	{
		if (stack != NULL)
		{
			if (stack->size > 0)
			{
				printf("\nPrint Linked Stack\n");
				int level = stack->size;
				Node *node = stack->top;
				for (int i = stack->size; node != NULL; i--)
				{
					printf("Level: %d Value: %d\n", i, node->value);
					node = node->next;
				}
			}
		}
	}

	int isEmpty(Stack* top) { return (top == NULL); }

}