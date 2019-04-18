#pragma once
#ifndef ARRAYGRAPH_HPP_INCLUDE
#define ARRAYGRAPH_HPP_INCLUDE

namespace ag {

	typedef void *Data;

	typedef struct _Vertex {
		int key;
		Data data;
	}Vertex;

	typedef struct _Graph {
		Vertex ***matrix;
		int num;
	};

}

#endif // !ARRAYGRAPH_HPP_INCLUDE