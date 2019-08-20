//DynamicArray
#include "DynamicArray.hpp"
//c style code

namespace da {

	int daUI()
	{
		DArray* arr;
		unsigned int size = 4;
		initArray(arr, size);
		insertArray(arr, 4, 1, 2, 3, 4);
		printArray(arr,4);
		return 0;
	}

	void initArray(DArray *a, int s)
	{
		a->array = (int*)malloc(sizeof(int)*s);
		a->used = 0;
		a->size = s;
	}

	void insertElement(DArray *a, int value, int index)
	{
		if ((index >= a->size - 1) || a->used == a->size)
		{
			a->size += index;
			a->array = (int*)realloc(a->array, a->size * sizeof(int));
		}
		a->array[index] = value;
	}

	void printArray(DArray *a, int size)
	{
		for (int i = 0; i < size; i++)
		{
			printf("%d\t", a->array[i]);
		}
	}
	void removeElement(DArray *a, unsigned int index)
	{
		if ((index <= a->size))
		{
			a->array[index] = 0;
			a->size--;
			a->used--;
		}
	}

	void insertArray(DArray *a, int size, int value,...)
	{
		a->size += size;
		a->array = (int *)realloc(a->array, a->size * sizeof(int));
		va_list ap;
		va_start(ap, size);
		for (int i = 0; i < size; i++)
			a->array[i] = va_arg(ap, int);
		va_end(ap);
	}
}