#include "sort.h"

/*
 * NOTE on COMPLEXITY:
 * same for three cases because merge sort divides
 * the array into two halves and takes linear times
 * to merge two halves
 *
 * merge_top_down - function that performs a sort and merge
 * on sub_array
 * @array: the array to sort and merge
 * @array_2: copy of array to store the sorted elements
 * @start: index of first element
 * @mid: index of middle element
 * @end: index of last element
 */

void merge_top_down(int *array, int *array_2, size_t start,
					size_t mid, size_t end)
{
	size_t k = 0;
	size_t i, j;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);
	for (i = start, j = mid; i < mid && j < end; k++)
	{
		if (array[i] < array[j])
			array_2[k] = array[i++];
		else
			array_2[k] = array[j++];
	}
	while (i < mid)
		array_2[k++] = array[i++];
	while (j < end)
		array_2[k++] = array[j++];

	i = 0;
	for (k = start; k < end; k++)
		array[k] = array_2[i++];
	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * recursive_merge - perform the "top-down" or recursive sorting
 * method on subarray
 * @array: the array to sort/merge
 * @array_2: copy of array to do our work
 * @start: index first element
 * @end: index last element
 */

void recursive_merge(int *array, int *array_2, size_t start, size_t end)
{
	size_t half;

	if (end - start > 1)
	{
		half = ((end - start) / 2 + start);
		recursive_merge(array, array_2, start, half);
		recursive_merge(array, array_2, half, end);
		merge_top_down(array, array_2, start, half, end);
	}
}

/**
 * merge_sort - sorts an array of integers using
 * top-down recrusive method
 * @array: the array to sort
 * @size: number of elements of the array
 */

void merge_sort(int *array, size_t size)
{
	int *array_2;

	if (!array || size < 2)
		return;

	array_2 = malloc(sizeof(int) * size);
	recursive_merge(array, array_2, 0, size);
	free(array_2);
}
