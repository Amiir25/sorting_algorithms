#include "sort.h"

/**
 * shell_sort - Sorts an array using Shell Sort Algorithm
 *
 * @array: The array
 * @size: Size of @array
 */

void shell_sort(int *array, size_t size)
{
	int gaps[100];
	int gap, count, temp, k;
	size_t i, j, n;

	count = 0;
	for (n = 1; n < size; n *= 3 + 1)
		gaps[count++] = n;

	for (k = count - 1; k >= 0; k--)
	{
		gap = gaps[k];
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; (int)j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = temp;
		}

		print_array(array, size);
	}
}
