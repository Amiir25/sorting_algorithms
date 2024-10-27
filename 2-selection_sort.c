#include "sort.h"

/**
 * selection_sort - Sorts an array using selection sort algorithm
 *
 * @array: The array
 * @size: The size of @array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int smallest, idx;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		smallest = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < smallest)
			{
				smallest = array[j];
				idx = j;
			}
		}

		array[idx] = array[i];
		array[i] = smallest;
		print_array(array, size);
	}
}
