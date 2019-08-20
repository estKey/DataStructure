#include "PriorityQueue.hpp"

namespace pq {

	Node *initNode(Data data, int priority)
	{
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->priority = priority;
		newNode->data = data;
		newNode->next = NULL;
		return newNode;
	}

	Queue *initQueue()
	{
		Queue *newQueue = (Queue *)malloc(sizeof(Queue));
		newQueue->size = 0;
		newQueue->head = NULL;
		return newQueue;
	}

	void enqueue(Data data, int priority, Queue *queue)
	{
		Node *node = initNode(data, priority);

	}

}