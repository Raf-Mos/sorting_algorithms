#include "sort.h"

/**
 * swap_val - swap elements of array
 * @array: array of elements
 * @size: size of array
 * @x: address of first value
 * @y: address of second value
 * Retrun: void
*/
void swap_val(int *array, size_t size, int *x, int *y)
{
	if (*x != *y)
	{
		*x = *x + *y;
		*y = *x - *y;
		*x = *x - *y;
		print_array(array, size);
	}
}
/**
 * lomuto_partition - partition the array
 * @array: array of elements
 * @size: size of array
 * @low_no: the lowest index in array
 * @high_no: the highest index in array
 * Return: size_t
 *
*/
size_t lomuto_partition(int *array, size_t size,
	       ssize_t low_no, ssize_t high_no)
{
	int i, j, pivot = array[high_no];

	for (i = j = low_no; j < high_no; j++)
		if (array[j] < pivot)
			swap_val(array, size, &array[j], &array[i++]);
	swap_val(array, size, &array[i], &array[high_no]);

	return (i);
}

/**
 * quicksort - quicksort by lomuto partition scheme
 * @array: array of elements
 * @size: size of array
 * @low_no: the lowest index in array
 * @high_no: the highest index in array
 * Return: void
*/
void quicksort(int *array, size_t size, ssize_t low_no, ssize_t high_no)
{
	if (low_no < high_no)
	{
		size_t parti = lomuto_partition(array, size, low_no, high_no);

		quicksort(array, size, low_no, parti - 1);
		quicksort(array, size, parti + 1, high_no);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array of elements
 * @size: size of array
 * Return: void
*/
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
