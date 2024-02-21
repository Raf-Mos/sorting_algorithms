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
