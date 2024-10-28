#include "sort.h"

/**
 * shell_sort - Sorts an array using Shell Sort Algorithm
 *
 * @array: The array
 * @size: Size of @array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	gap = 1;
	while (gap < size / 3)
		gap *= 3 + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}

		print_array(array, size);
		gap /= 3;
	}
}
