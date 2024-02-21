#include "sort.h"

/**
 * swap_elements - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap_elements(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - Order a subset of an array of integers
 *             according to the partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @l: The starting index
 * @r: The ending index
 *
 * Return: The final partition index.
 */
int partition(int *array, size_t size, int l, int r)
{
	int pivot, i, j;

	pivot = array[r];
	for (i = l - 1, j = r + 1; i < j;)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap_elements(array + i, array + j);
			print_array(array, size);
		}
	}

	return (i);
}

/**
 * sort_hoare - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @l: The starting index
 * @r: The ending index
 */
void sort_hoare(int *array, size_t size, int l, int r)
{
	int divide;

	if (r - l > 0)
	{
		divide = partition(array, size, l, r);
		sort_hoare(array, size, l, divide - 1);
		sort_hoare(array, size, divide, r);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *             order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_hoare(array, size, 0, size - 1);
}
