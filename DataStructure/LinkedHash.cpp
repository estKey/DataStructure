#include "LinkedHash.hpp"

namespace lh {

	int lhUI()
	{
		HashTable *ht = initHashTable(101);

		return 0;
	}

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

	HashTable *initHashTable(int size)
	{
		HashTable *newHashTable = (HashTable *)malloc(sizeof(HashTable));
		newHashTable->size = size;
		newHashTable->collision = 0;
		newHashTable->hashlist = (Hash **)malloc(sizeof(Hash)*size);
		for (int i = 0; i < size; i++)
			newHashTable->hashlist[i] = initHash();
		return newHashTable;
	}

	void *RandHtGen(HashTable *h, int n)
	// Generate Random Hash Table with n Elements
	{
		for (int i = 0; i< n; i++) {
			int x = rand() % 5 + 1;
			Data p = (Data)malloc(sizeof(char)*x);
			int j = 0;
			for (j = 0; j<x; j++)
				p[j] = rand() % 26 + 97;
			p[j] = '\0';
			printf("%d %s\n", i + 1, p);
			insert(p, h);
		}
	}

	void addFront(Data data, Hash *hashlist)
	{
		Node *node = initNode(data);
		if (hashlist->head)
		{
			// if the list is not empty it means collision occurs
			hashlist->collision++;
			node->next = hashlist->head;
			hashlist->head->prev = node;
			hashlist->head = node;
		}
		else
		{
			hashlist->head = node;
			hashlist->tail = node;
			node->prev = hashlist->head;
		}
	}

	Node *find(Data data, HashTable *hashtable)
	{
		int index = hashCode(data, hashtable->size);
		Node *node = hashtable->hashlist[index]->head;
		while (node->next || !strcmp(node->data, data))
			node = node->next;
		if(!strcmp(node->data, data))
			return node;
		else return NULL;
	}

	Node *extract(Data data, HashTable *hashtable)
	//remove the data from the hash tale and sotre the original properties
	{
		Node *del = find(data, hashtable);
		if (del) {
			if (!strcmp(hashtable->hashlist[hashCode(data, hashtable->size)]->head->data, data))
			{
				del->prev->next = del->next;
				del->next->prev = del->prev;
			}
			else hashtable->hashlist[hashCode(data, hashtable->size)]->head = NULL;
		}
		return del;
	}

	int hashCode(Data data, int size)
	{
		int code;
		int n = strlen(data);
		for (int i = 0; data[i]; i++)
			code += data[i] * pow(31, (n - 1 - i));
		return code%size;
	}

	double loadFactor(HashTable* ht)
	{
		double nonempty = 0;
		int i;
		// count number of non-empty hash table slots
		for (i = 0; i<ht->size; i++) {
			if (isEmpty(ht->hashlist[i]) == 0)	nonempty++;
		}
		return nonempty / ht->size * 100;
	}

	int enlarge(HashTable *h)
	// Enlarging Table when load factor gets high
	{
		if (h) {
			if (loadFactor(h) > 60)
			{
				h->size *= 2;
				h->hashlist = (Hash **)realloc(h->hashlist, (sizeof(Hash) *(h->size)));
				for (int i = h->size / 2; i <= h->size; i++)
					h->hashlist[i] = initHash();
			}
		}
		return 0;
	}

	void insert(Data data, HashTable *hashtable)
	{
		int index = hashCode(data, hashtable->size);
		addFront(data, hashtable->hashlist[index]);
		hashtable->collision += hashtable->hashlist[index]->collision;
	}

	void printList(Hash *ll)
	{
		if (ll != NULL) {
			Node* ptr = ll->head;
			while (ptr != NULL) {
				printf("%s -", ptr->data);
				ptr = ptr->next;
			}
		}
		else {
			printf("--EMPTY--");
		}
		printf("\n");
	}

	void printTable(HashTable *ht)
	{
		printf("----------Hash Table----------\n");
		for (int i = 0; i < ht->size; i++) {
			printf("%d --> ", i);
			printList(ht->hashlist[i]);
		}
		printf("# of Collisions=%d\n", ht->collision);
		printf("Load Factor %%=%.2f\n----------", loadFactor(ht));
	}

	int isEmpty(Hash *hash)
	{
		return ((hash != NULL) && (hash->head != NULL)) ? 0 : 1;
	}

}