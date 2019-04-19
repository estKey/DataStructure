#include "ArrayHash.hpp"

namespace ah {

	int ahUI()
	{

		return 0;
	}

	HashTable *initHash(int size)
	{
		HashTable *newHashTable = (HashTable *)malloc(sizeof(HashTable));
		newHashTable->size = size;
		newHashTable->collisions = (int *)malloc(sizeof(int *)*size);
		memset(newHashTable->collisions, 0, size);
		newHashTable->a = (ArrayList *)malloc(sizeof(Data *)*size);
		memset(newHashTable->a, -1, size);
		return newHashTable;
	}

	int hashCode(char* value, HashTable *ht)
	{
		int key = 0;
		for (int i = 0; i < strlen(value); i++)
			key += value[i];
		return key % (ht->size);
	}

	void insert(char *value, HashTable *ht)
	{
		int key = hashCode(value, ht);
		ht->a[key]->key = key;
		strcpy((ht->a[key]->value), value);
	}

	int LinearProbing()
	{
		int key;
		return key;
	}

	int QuadraticProbing()
	{
		int key;
		return key;
	}

	int DoubbleHashing()
	{
		int key;
		return key;
	}

	int searchId(char *value, HashTable *ht)
	{
		int key;

		return key;
	}

	Data *searchItem(int key, HashTable *ht)
	{
		Data *dist;

		return dist;
	}

	void printTable(HashTable *ht)
	{
		for (int i = 0; i < ht->size; i++)
			printf("%d\n", ht->a[i]);
	}

}