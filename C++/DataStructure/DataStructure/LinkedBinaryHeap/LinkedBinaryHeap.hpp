#pragma once
#ifndef LIKNEDHEAP_HPP_INCLUDE
#define LIKNEDEAP_HPP_INCLUDE

namespace lbh {
	typedef struct _Node {
		int value;
		struct _Node *leftChild;
		struct _Node *rightChild;
	}Node;


}

#endif