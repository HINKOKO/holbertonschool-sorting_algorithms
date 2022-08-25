#include "sort.h"

/**
 * Lomuto - lomuto partition scheme, choose a pivot
 * right here the last element of array
 * @array: pointer to first element of array
 * @low: left-most element of array
 * @high: right-most element of array
 * @size: number of elements in array
 * Return: next sorting element location
 */

size_t Lomuto(int *array, int low, int high, size_t size)
{
	int i, idx, pivot, swap;

	i = low;
	pivot = array[high];

	for (idx = low; idx < high; ++idx)
	{
		if (array[idx] < pivot)
		{
			i++;
			if (i != idx)
			{
				swap = array[i];
				array[i] = array[idx];
				array[idx] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		swap = array[high];
		array[high] = array[i + 1];
		array[i + 1] = swap;
		print_array(array, size);
		/* set the high index value to its sorted position */
	}
	return (i + 1); /* returns the next sorting element location */
}
void quicksort(int *array, int start, int end, size_t size)
{
	size_t pivot;

	if (start < end)

	{
		pivot = Lomuto(array, start, end, size);
		quicksort(array, start, pivot - 1, size);
		quicksort(array, pivot + 1, end, size);
	}
}

void quick_sort(int *array, size_t size)
{
	if (!array)
		return;
	quicksort(array, 0, size - 1, size);
}
