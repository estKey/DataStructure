#include "LinkedGraph.hpp"

namespace lg {

	int graphUI(void)
	{
		int size = 5;
		Graph *graph = initGraph(size);
		return 0;
	}

	Graph *initGraph(int size) {
		Graph *newGraph = (Graph *)malloc(sizeof(Graph *));
		newGraph->size = size;
		newGraph->VertexSet = (Vertex **)malloc(sizeof(Vertex*) * size);
		return newGraph;
	}

	Vertex *initVertex(Data data, int key)
	{
		Vertex *newVertex = (Vertex *)malloc(sizeof(Vertex *));
		newVertex->data = data;
		newVertex->key = key;
		return newVertex;
	}

	Linker *initLinker(Vertex *prev, Vertex *next)
	{
		Linker *newLink = (Linker *)malloc(sizeof(Linker *));
		newLink->prev = prev;
		newLink->next = next;
		return newLink;
	}

	EdgeSet *initEdgeSet(int n)
	{
		EdgeSet *newSet = (EdgeSet *)malloc(sizeof(EdgeSet));
		newSet->EdgeSet = (Linker *)malloc(sizeof(Linker) * n);
		return newSet;
	}

	void insert(Vertex *v, Graph *g, int i)
	{
		if (v && g->VertexSet)
			g->VertexSet[i] = v;
	}

	void pushVertex(Graph *g)
	{

	}
}