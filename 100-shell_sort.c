#include "sort.h"

/**
 * shell_sort - sorts an array in increasing order using
 * Shell sort algorithm and the Knuth sequence for gapping
 * @array: pointer to first element of array
 * @size: number of elements in array
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int temp;

	if (size < 2)
		return;

	while ((gap = gap * 3 + 1) < size)
		;
	gap = (gap - 1) / 3;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
