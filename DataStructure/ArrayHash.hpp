#pragma once
#ifndef ARRAYHASH_HPP_INCLUDE
#define ARRAYHASH_HPP_INCLUDE

namespace ah {
#include "common.hpp"
	typedef char* Data;
	typedef Data* HashTable;
	typedef struct _Hash
	{
		int size;
		HashTable hashtable;
	}Hash;

	Hash *initHash(int size);
	int hashCode(Data data, Hash *hash);
	void insert(Data data, Hash *hash);

}

#endif
