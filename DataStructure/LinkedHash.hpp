#pragma once
#ifndef LINKEDHASH_HPP_INCLUDE
#define LINKEDHASH_HPP_INCLUDE

namespace lh {
#include "common.hpp"

	typedef char* Data;
	typedef struct _Node
	{
		Data data;
		struct _Node *prev;
		struct _Node *next;
	}Node;

	typedef struct _Hash
	// Basically a Linked List
	{
		unsigned int collision;
		Node *head;
		Node *tail;
	}Hash;

	typedef struct _HashTable
	{
		int size;
		unsigned int collision;
		Hash **hashlist;
	}HashTable;
	Node *initNode(Data data)
	{
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->data = (Data)malloc(sizeof(char)*(strlen(data)));
		strcpy(newNode->data, data);
		newNode->prev = NULL;
		newNode->next = NULL;
		return newNode;
	}

	Hash *initHash()
		// hash list has the same structure of the linked list
	{
		Hash *newHash = (Hash *)malloc(sizeof(Hash));
		newHash->head = NULL;
		newHash->tail = NULL;
		newHash->collision = 0;
		return newHash;
	}

	HashTable *initHashTable(int size);
	void *RandHtGen(HashTable *h, int n);
	void addFront(Data data, Hash *hashlist);
	Node *find(Data data, HashTable *hashtable);
	Node *extract(Data data, HashTable *hashtable);
	int hashCode(Data data, int size);
	double loadFactor(HashTable* ht);
	int enlarge(HashTable *h);
	void insert(Data data, HashTable *hashtable);
	void printList(Hash *ll);
	void printTable(HashTable *ht);
	int isEmpty(Hash *hash);

}

#endif	//LINKEDHASH_HPP_INCLUDE
