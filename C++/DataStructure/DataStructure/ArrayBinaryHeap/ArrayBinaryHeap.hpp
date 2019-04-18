#pragma once
#ifndef ARRAYHEAP_HPP_INCLUDE
#define ARRAYHEAP_HPP_INCLUDE

namespace abh {
	typedef void* Data;
	typedef struct _Node {
		Data data;
		struct _Node *leftChild;
		struct _Node *rightChild;
	}Node;
	typedef struct _Heap {
		int size;
		int *array;
	};
}

#endif