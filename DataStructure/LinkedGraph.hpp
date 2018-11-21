#pragma once
#ifndef LINKEDGRAPH_HPP_INCLUDE
#define LINKEDGRAPH_HPP_INCLUDE

namespace lg {

#include "common.hpp"
	typedef void *Data;

	typedef struct _Vertex {
		int key;
		Data data;
	}Vertex;

	typedef struct _Graph {
		Vertex **VertexSet;
		int size;
	}Graph;

	typedef struct _Linker {
		Vertex *prev;
		Vertex *next;
	}Linker;

	typedef struct _EdgeSet {
		Linker *EdgeSet;
	}EdgeSet;

}

#endif // !LINKEDGRAPH_HPP_INCLUDE