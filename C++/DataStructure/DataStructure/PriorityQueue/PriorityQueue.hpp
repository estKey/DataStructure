#pragma once
#ifndef PRIORITYQUEUE_HPP_INCLUDE
#define PRIORITYQUEUE_HPP_INCLUDE

namespace pq {
#include "common.hpp"

	typedef void* Data;

	typedef struct _Node
	{
		int priority;
		Data data;
		struct _Node *next;
	}Node;

	typedef struct _Queue
	{
		int size;
		Node *head;
	}Queue;


}

#endif // !PRIORITYQUEUE_HPP_INCLUDE
