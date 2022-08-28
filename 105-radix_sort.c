#include "sort.h"

/**
 * get_max - determine max value of array
 * @array: array in which to find max value
 * @size: number of elements of array
 * Return: max value found
 */

int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * radix_sort - radix sort is incredible
 * @array: to array to be radixed
 * @size: number of elements of array
 */

void radix_sort(int *array, size_t size)
{
	int j, bucket[10][10], bucket_cnt[10];
	size_t i, k, r, NOP = 0, divisor = 1, lar, pass;

	if (!array || size < 2)
		return;
	lar = get_max(array, size);
	while (lar > 0)
	{
		NOP++;
		lar /= 10;
	}
	for (pass = 0; pass < NOP; pass++)
	{
		for (i = 0; i < 10; i++)
		{
			bucket_cnt[i] = 0;
		}
		for (i = 0; i < size; i++)
		{
			r = (array[i] / divisor) % 10;
			bucket[r][bucket_cnt[r]] = array[i];
			bucket_cnt[r] += 1;
		}
		i = 0;
		for (k = 0; k < 10; k++)
		{
			for (j = 0; j < bucket_cnt[k]; j++)
			{
				array[i] = bucket[k][j];
				i++;
			}
		}
		print_array(array, size);
		divisor *= 10;
	}
}
