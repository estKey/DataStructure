#include "StackQueue.hpp"

namespace sq {

	int sqUI()//put this funtion into main to see the sample
	{
		Queue *queue = initQueue();
		Node *del = NULL;
		enqueue(1, queue);
		enqueue(2, queue);
		enqueue(3, queue);
		enqueue(4, queue);
		enqueue(5, queue);
		printQueue(queue);
		dequeue(queue);
		printQueue(queue);
		del = dequeue(queue);
		dequeue(queue);
		dequeue(queue);
		enqueue(6, queue);
		printQueue(queue);
		dequeue(queue);
		dequeue(queue);
		printQueue(queue);
		printf("%d\n\n", del->value);
		enqueue(9, queue);
		printQueue(queue);
		return 0;
	}

	Node *initNode(int v)
	{
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->value = v;
		newNode->next = NULL;
		return newNode;
	}

	Stack *initStack()
	{
		Stack *newStack = (Stack *)malloc(sizeof(Stack));
		newStack->size = 0;
		newStack->top = NULL;
		return newStack;
	}

	Queue *initQueue()
	{
		Queue *newQueue = (Queue*)malloc(sizeof(Queue));
		newQueue->Sin = initStack();
		newQueue->Sout = initStack();
		return newQueue;
	}

	void push(int v, Stack *stack)
	{
		if (stack)
		{
			if (!stack->top)
			{
				stack->top = initNode(v);
				(stack->size)++;
			}
			else
			{
				Node *node = initNode(v);
				node->next = stack->top;
				stack->top = node;
				(stack->size)++;
			}
		}
	}

	Node *pop(Stack *stack)
	{
		if (stack)
		{
			if (stack->top)
			{
				Node *del = stack->top;
				stack->top = stack->top->next;
				(stack->size)--;
				return del;
			}
		}
	}

	void enqueue(int v, Queue *queue)
	{
		if (queue)
			push(v, queue->Sin);
	}

	Node *dequeue(Queue *queue)
	{
		if (queue->Sin->top || queue->Sout->top)
		{
			Node *del = NULL;
			if (queue->Sin->top)
			{
				while (queue->Sin->top)
				{
					Node *node = pop(queue->Sin);
					push(node->value, queue->Sout);
				}
			}
			del = pop(queue->Sout);
			return del;
		}
	}

	void printQueue(Queue *queue)
	{
		if (queue->Sin->top || queue->Sout->top)
		{
			printf("front\n");
			if (queue->Sout->top)
			{
				Node *node = queue->Sout->top;
				while (node)
				{
					printf("%d\n", node->value);
					node = node->next;
				}
			}
			if (queue->Sin->top)
			{
				Node *node = queue->Sin->top;
				Stack *tmp = initStack();
				while (node)
				{
					push(node->value, tmp);
					node = node->next;
				}
				node = tmp->top;
				while (node)
				{
					printf("%d\n", node->value);
					node = node->next;
				}
			}
			printf("rear\n\n");
		}
		else
			printf("EMPTY\n\n");
	}
}