#pragma once
#ifndef DYNAMICARRAY_HPP_INCLUDE
#define DYNAMICARRAY_HPP_INCLUDE

namespace da {
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
	typedef int type;
	typedef struct _Array
	{
		int *array;
		type used;
		type size;
	}DArray;

	int daUI();

	void insertElement(DArray *a, int value, unsigned int index);
	void removeElement(DArray *a, int index);
	void insertArray(DArray *a, int size, int value, ...);

	//DArray*	search(int v, darr *list);
	//void	sortArray(darr *list);
	//DArray*	extract(int v, darr *list);
	//void	breakList(darr *list);

	void	initArray(DArray *a, int s);
//	int		isEmpty(darr *l);
	void	printArray(DArray *a, int size);


}

#endif // !DYNAMICARRAY_HPP_INCLUDE
