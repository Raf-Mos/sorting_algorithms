#include "sort.h"

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
	int tmp, pivot, i = l, j = r;

	pivot = array[r];
	while (i < j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;

		if (i < j && array[i] != array[j])
		{
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
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
 * hoare_quicksort - Sort an array of integers in ascending
 *             order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void hoare_quicksort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_hoare(array, size, 0, size - 1);
}
