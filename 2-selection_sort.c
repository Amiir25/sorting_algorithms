#include "sort.h"

/**
 * selection_sort - Sorts an array using selection sort algorithm
 *
 * @array: The array
 * @size: The size of @array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[idx])
				idx = j;
		}

		if (idx != i)
		{
			temp = array[i];
			array[i] = array[idx];
			array[idx] = temp;
			print_array(array, size);
		}
	}
}
