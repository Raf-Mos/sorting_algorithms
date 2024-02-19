#include "sort.h"
#include <stdbool.h>

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
 * bubble_sort - that sorts an array of integers in ascending order
 * @array: array of elements
 * @size: size of array
 * Return: void
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;
				print_array(array, size);
			}
		}
		if (swapped == false)
			break;
	}
}
