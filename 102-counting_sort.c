#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *k, *sorted_array, max, i;

	if (array == NULL || size < 2)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;
	max = get_max(array, size);
	k = malloc(sizeof(int) * (max + 1));
	if (k == NULL)
	{
		free(sorted_array);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		k[i] = 0;
	for (i = 0; i < (int)size; i++)
		k[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		k[i] += k[i - 1];
	print_array(k, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted_array[k[array[i]] - 1] = array[i];
		k[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	free(sorted_array);
	free(k);
}
