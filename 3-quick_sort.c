#include "sort.h"

/**
 * quick_sort - Sorts an array using Quick sort algorithm
 *
 * @array: The array
 * @size: The size of @array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}

/**
 * quick_sort_recursion - Recursive function for Quick Sort
 *
 * @array: The array
 * @low: The starting point of partitioning
 * @high: The end of partitionning
 * @size: The size of @array
 */

void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_recursion(array, low, pivot_index - 1, size);
		quick_sort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * lomuto_partition - Performs a Lomuto Partition for Quick Sort
 * @array: The array
 * @low: The starting point of partitioning
 * @high: The end of partitionning
 * @size: The size of @array
 *
 * Return: The pivot index
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}
