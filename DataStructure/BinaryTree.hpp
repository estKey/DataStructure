#pragma once
#ifndef BINARYTREE_HPP_INCLUDE
#define BINARYTREE_HPP_INCLUDE


namespace bt {

#include "common.hpp"

	typedef int Key;
	typedef void* type;

	typedef struct _Node {
		Key key;
		type value;
		struct _Node *parent;
		struct _Node *leftChild;
		struct _Node *rightChild;
	}Node, *pNode;

	typedef struct _BinaryTree {
		int height;
		Node *root;
	}BinaryTree;

	typedef struct _bst	BST, *pBST;
	struct _bst {
		pNode	proot;
		int(*keycmp)(void *key1, void *key2);
	};

	int btUI();
	BinaryTree *initTree(Key key, type value);
	Node *createNode(Key key, type value, Node *parent, Node *left, Node *right);
	Node *initNode(Key key, type value);
	void insertChild(Key key, type value, Node *root, BinaryTree *tree);
	void insert(Key key, type value, BinaryTree *tree);

	void preorder(Node *root);
	void inorder(Node *root);
	void postorder(Node *root);

	int getNumber(char ch);
	int isNumber(char ch);
	int isEmpty(Node* node);
}

#endif
