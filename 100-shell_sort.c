#include "sort.h"

/**
 * shell_sort - Sorts an array using Shell Sort Algorithm
 *
 * @array: The array
 * @size: Size of @array
 */

void shell_sort(int *array, size_t size)
{
	int gap;
	size_t i, j, x, y, temp;

	gap = size / 2;
	while (gap >= 1)
	{
		j = 0;
		for (i = gap; i < size; i++)
		{
			if (gap == 1)
			{
				x = i;
				y = j;
				while (array[x] < array[y])
				{
					temp = array[x];
					array[x] = array[y];
					array[y] = temp;
					x--;
					y--;
				}
			}

			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			j++;
		}
		gap /= 2;
		print_array(array, size);
	}
}
