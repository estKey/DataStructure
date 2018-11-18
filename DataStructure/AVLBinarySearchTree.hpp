#pragma once
#ifndef AVLBINARYSEARCHTREE_HPP_INCLUDE
#define AVLBINARYSEARCHTREE_HPP_INCLUDE


namespace avlbst {
#include "common.hpp"

#define MAXINT(a, b) ((a) > (b)?(a):(b));
	typedef int Key;
	typedef void* Value;
	typedef struct Node {
		Key key;
		Value value;
		int height;
		struct Node *leftChild;
		struct Node *rightChild;
	}Node, *Root;

	typedef struct _tree
	{
		Root root;
	}Tree;
	
	Tree *initTree();
	Node *initNode(Key k, Value v);
	Node *insertNode(Key k, void *v, Node *root);
	void deleteNode(Node* p, Node *n);
	Node *removeNode(Root root, Key k);
	void insert(Key k, void *v, Tree *t);

}

#endif