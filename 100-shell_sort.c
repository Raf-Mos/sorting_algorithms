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
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;

	if (array == NULL || size < 2)
		return;

	while (gap < (size / 3))
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
			{
				swap(array + j, array + (j - gap));
			}
		}
		print_array(array, size);
	}
}
