#include "ArrayQueue.hpp"

namespace aq {

	int aqUI()
	{
		Queue *queue = initQueue(5);
		enQueue(queue, 1);
		enQueue(queue, 2);
		enQueue(queue, 3);
		printQueue(queue);
		deQueue(queue);
		printQueue(queue);
		return 0;
	}

	Queue *initQueue(int size)
	{
		printf("Initializing Queue with size %d\n", size);
		Queue *newQueue = (Queue *)malloc(sizeof(Queue));
		newQueue->size = size;
		newQueue->head = 0;
		newQueue->tail = 0;
		newQueue->array = (type *)malloc(sizeof(type)*size);
		return newQueue;
	}

	void enQueue(Queue *queue, type value)
	{
		if (queue->size >= queue->tail+1)
		{
			++queue->tail;
			queue->array[queue->tail] = value;
			queue->size++;
		}
		else {
			queue->size *= 2;
			queue->array=(type*)realloc(queue->array, sizeof(type)*(queue->size));
			++queue->tail;
			queue->array[queue->tail] = value;
			queue->size++;
		}
	}

	int deQueue(Queue *queue)
	{
		if (!isEmpty(queue))
		{
			int dequeue = queue->array[queue->head];
			for (int i = 0; i < queue->tail; i++)
				queue->array[i] = queue->array[i + 1];
			queue->tail--;
			queue->size--;
			return dequeue;
		}
	}

	void printQueue(Queue *queue)
	{
		if (!isEmpty(queue))
		{
			for (int i = 0; i <= queue->tail; i++)
				printf("Memeber %d\tValue %d\n", i+1, queue->array[i]);
		}
		else printf("NULL\n");
		printf("\n");
	}

	int isEmpty(Queue *queue)
	{
		return (queue->size == 0);
	}
}