#pragma once
#ifndef ARRAYHASH_HPP_INCLUDE
#define ARRAYHASH_HPP_INCLUDE

namespace ah {
#include "common.hpp"
	typedef struct Data
	{
		int key;
		char *value;
	}Data;
	typedef Data* ArrayList;
	typedef struct _HashTable
	{
		int size;
		int *collisions;
		ArrayList *a;
	}HashTable;

	HashTable *initHash(int size);
	int hashCode(Data data, HashTable *ht);
	void insert(Data data, HashTable *ht);

}

#endif
