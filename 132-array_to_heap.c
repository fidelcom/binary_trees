#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap from an array.
 * @array: first element of the array.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the Max Binary Heap, or NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *t;
	size_t i;

	t = NULL;

	for (i = 0; i < size; i++)
	{
		heap_insert(&t, array[i]);
	}

	return (t);
}

