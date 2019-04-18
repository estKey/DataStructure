#pragma once
#ifndef ARRAYQUEUE_HPP_INCLUDE
#define ARRAYQUEUE_HPP_INCLUDE

namespace aq {
#include <stdio.h>
#include <stdlib.h>

	typedef int type;
	typedef struct Queue {
		int size;
		int head;
		int tail;
		type *array;
	}Queue;

	int aqUI();
	Queue *initQueue(int size);
	void enQueue(Queue *queue, type value);
	int deQueue(Queue *queue);
	void printQueue(Queue *queue);
	int isEmpty(Queue *queue);

}

#endif
