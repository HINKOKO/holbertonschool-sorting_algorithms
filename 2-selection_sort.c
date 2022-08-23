#include "sort.h"

/**
 * swap - Srwapping machine
 * @array - the array in which we may need to swap
 * @x: to be swapped with y
 * @y: to be swapped with x
 */

void swap(int *array, int x, int y)
{
	int temp;

	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

/**
 * selection_sort - sorts an array of integers, in ascending order
 * using Selection Sort
 * @array: the array to sort
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min = 0;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (i != min)
		{
			/** swap min element at i index */
			swap(array, i, min);
			print_array(array, size);
		}
	}
}
