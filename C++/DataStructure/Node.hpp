#pragma once

// Node
template <class T>
class Node
{
private:
	int id;
public:
	T* next;
};

typedef struct _Node
{
	struct _Node* next;
} Node;