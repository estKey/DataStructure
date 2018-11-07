#include "LinkedHash.hpp"

namespace lh {

	int lhUI()
	{
		return 0;
	}

	Node *initNode(Data data, int key)
	{
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->data = data;
		newNode->key = key;
		newNode->next = NULL;
		return newNode;
	}

	Hash *initHash(int key)
	{
		Hash *newHash = (Hash *)malloc(sizeof(Hash));
		newHash->head = NULL;
		newHash->size = 0;
		newHash->key = key;
		return newHash;
	}

	HashTable *initHashTable()
	{
		HashTable *newHashTable = (HashTable *)malloc(sizeof(HashTable));
		newHashTable->size = HashValue;
		newHashTable->hashlist = NULL;
	}

	int hashCode(Data data)
	{
		int code;
		int str = atoi(data);

		return code;
	}

	void insertNode(Data data, int key, Hash *hash)
	{
		Node *newNode = initNode(data, key);
		newNode->next = hash->head;
		hash->head = newNode;
		(hash->size)++;
	}

	void insertHash(Hash *hash, HashTable *hashtable)
	{
		hashtable->hashlist = (Hash **)malloc(sizeof(Hash)*(hashtable->size));
		(hashtable->hashlist)[hashtable->size] = hash;
	}

	void insert(Data data, HashTable *hashtable)
	{
		int key = 0;
	}

}