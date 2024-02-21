#include "sort.h"


/**
 * swap - swaping elements
 * @xp: input
 * @yp: input
 * Return: void
 */

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t l, r, large;

	l = 2 * root + 1;
	r = 2 * root + 2;
	large = root;

	if (l < base && array[l] > array[large])
		large = l;
	if (r < base && array[r] > array[large])
		large = r;

	if (large != root)
	{
		swap(&array[root], &array[large]);
		print_array(array, size);
		heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
