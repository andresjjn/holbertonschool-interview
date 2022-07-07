#include "sort.h"

/**
 * radix_sort - sorts by RADIX
 * @array: array
 * @size: size
 * Return: -
 */
void radix_sort(int *array, size_t size)
{
	size_t index;
	long dig = 1;
	int *h_arr,  bggr = INT_MIN;

	if (size < 2 || !array)
	{
		return;
	}

	h_arr = malloc(sizeof(int *) * size);
	if (!h_arr)
	{
		return;
	}

	for (index = 0; index < size; index++)
	{
		bggr = array[index] > bggr ? array[index] : bggr;
	}

	while (bggr / dig > 0)
	{
		current_digit_sort(array, size, h_arr, dig);
		print_array(array, size);
		dig *= 10;
	}
	free(h_arr);
}

/**
 * current_digit_sort - sort
 * @arr: array
 * @sz: size
 * @h_arr: temporal array
 * @dig: digit
 * Return: -
 */
int current_digit_sort(int *arr, ssize_t sz, int *h_arr, long dig)
{
	ssize_t index;
	int aux_arr[10] = {0};

	for (index = 0; index < sz; index++)
	{
		aux_arr[(arr[index] / dig) % 10]++, h_arr[index] = 0;
	}

	for (index = 1; index < 10; index++)
	{
		aux_arr[index] += aux_arr[index - 1];
	}

	for (index = sz - 1; index >= 0; index--)
	{
		h_arr[--aux_arr[(arr[index] / dig) % 10]] = arr[index];
	}
	for (index = 0; index < sz; index++)
	{
		arr[index] = h_arr[index];
	}
	return (0);
}
