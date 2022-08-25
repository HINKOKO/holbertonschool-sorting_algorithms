#include "sort.h"

/**
 * shell_sort - sorts an array in increasing order using
 * Shell sort algorithm and the Knuth sequence for gapping
 * @array: pointer to first element of array
 * @size: number of elements in array
 */

void shell_sort(int *array, size_t size)
{
	size_t i, gap = 1;
	int j, k;

	while (gap <= (size - 1) / 9)
		gap = gap * 3 + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			k = array[i];
			for (j = i - gap; j >= 0 && k < array[j]; j -= gap)
				array[j + gap] = array[j];
			array[j + gap] = k;
		}
		gap /= 3;
		print_array(array, size);
	}
}
