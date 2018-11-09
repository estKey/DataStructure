#include "ArrayHash.hpp"

namespace ah {

	int ahUI()
	{

		return 0;
	}

	Hash *initHash(int size)
	{
		Hash *newHashTable = (Hash *)malloc(sizeof(Hash));
		newHashTable->hashtable = (HashTable)malloc(sizeof(HashTable)*size);
		newHashTable->size = size;
		return newHashTable;
	}

	int hashCode(Data data, Hash *hash)
	{
		int key = 0;
		for (int i = 0; i < strlen(data); i++)
			key *= 1 + data[i];
		return key;
	}

	void insert(Data data, Hash *hash)
	{
		int key = hashCode(data, hash);
		*(hash->hashtable[key]) = *data;
	}

	int searchId(Data data, Hash *hash)
	{
		int dist;

		return dist;
	}

	Data searchItem(int index, Hash *hash)
	{
		Data dist;

		return dist;
	}

}