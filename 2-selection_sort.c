#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_val;

	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_val = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_val])
			min_val = j;
		}
		if (min_val != i)
		{
			swap(&array[min_val], &array[i]);
			print_array(array, size);
		}
	}
}
