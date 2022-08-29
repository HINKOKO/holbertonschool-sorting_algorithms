#include "sort.h"

/**
 * counting_sort - function that sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: is the pointer that points the first element of array
 * @size: is the size of the array
 */

void counting_sort(int *array, size_t size)
{
	int index = 0;
	int max = -1;
	size_t output[size];

	/* Find the largest element in the array */
	for (index = 0; index < (int)size; index++)
	{
		if (array[index] > max)
			max = array[index];
	}
	max = max + 1;
	/* Giving memory to count and Initializing count array with all zeros */
	int *count = calloc(sizeof(int), max);
	/* Protecting count if it doesn't exist return */
	if (!count)
		return;
	/* Store count of each elements */
	for (index = 0; index < (int)size; index++)
	{
		count[array[index]] += 1;
	}
	/* Store the cumulative count of each array */
	for (index = 0; index < max; index++)
	{
		count[index] += count[index - 1];
	}
	print_array(count, max);
	/* Place the elements in output array */
	for (int index = size - 1; index >= 0; index--)
	{
		output[count[array[index]] - 1] = array[index];
		count[array[index]]--;
	}

	for (index = 0; index < (int)size; index++)
	{
		array[index] = output[index];
	}
}
