#pragma once
#ifndef STACKQUEUE_HPP_INCLUDE
#define STACKQUEUE_HPP_INCLUDE

namespace sq {
#include "common.hpp"

	typedef struct _Node {
		int value;
		struct _Node *next;
	}Node;

	typedef struct _Stack {
		int size;
		Node *top;
	}Stack;

	typedef struct _Queue {
		Stack *Sin;
		Stack *Sout;
	}Queue;


	int sqUI();
	Node *initNode(int v);
	Stack *initStack();
	Queue *initQueue();
	void push(int v, Stack *stack);
	Node *pop(Stack *stack);
	void enqueue(int v, Queue *queue);
	Node *dequeue(Queue *queue);
	void printQueue(Queue *queue);

}
#endif //STACKQUEUE_HPP_INCLUDE