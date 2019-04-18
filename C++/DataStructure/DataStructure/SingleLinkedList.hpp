#pragma once
#ifndef SINGLELINKEDLIST_HPP_INCLUDE
#define SINGLELINKEDLIST_HPP_INCLUDE

#include <iostream>

namespace sll {

	typedef struct Node {
		int			value;
		struct Node	*next;
	} Node;

	// LinkedList structure has pointer to first element, and count of
	// elements in list.
	typedef struct LinkedList {
		Node	*head;
		int		size;
	} LinkedList;

	//User interface for Singlely Linked List
	int		sllUI();


	Node	*createNode(int v, Node *nxt);
	void	addFront(int v, LinkedList *l);
	void	addEnd(int v, LinkedList *l);
	void	insertFront(LinkedList *l);	// prepend
	void	insertEnd(LinkedList *l);	// append
	void	insert(LinkedList *l, Node *node, int pos);
	void	removeFront(LinkedList *l);
	void	removeEnd(LinkedList *l);

	int		search(int v, LinkedList *list);
	void	sortList(LinkedList *list);
	Node	*extract(int v, LinkedList *list);
	void	printExtract(Node *node);
	void	destroy(LinkedList *list);
	void	decay(LinkedList* l);
	Node *reverseRecursion(Node *head);
	Node *reverseIteration(Node *head);

	LinkedList	*initList();
	int		isEmpty(LinkedList *l);
	void	printList(LinkedList *l);

}


#endif // !SINGLELINKEDLIST_HPP_INCLUDE
