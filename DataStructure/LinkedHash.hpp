#pragma once
#ifndef LINKEDHASH_HPP_INCLUDE
#define LINKEDHASH_HPP_INCLUDE

namespace lh {
#include "common.hpp"

	int HashValue = 1024;
	typedef char* Data;
	typedef struct _Node
	{
		int key;
		Data data;
		struct _Node *next;
	}Node;
	typedef struct _Hash
	{
		int size;
		int key;
		Node *head;
	}Hash;
	typedef struct _HashTable
	{
		int size;
		Hash **hashlist;
	}HashTable;

	Node *initNode(Data data, int key);
	Hash *initHash(int size);
	HashTable *initHashTable();
	int hashCode(Data data);
	void insert(Data data, HashTable *hashtable);

}

#endif	//LINKEDHASH_HPP_INCLUDE
