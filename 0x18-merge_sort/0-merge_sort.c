#include "sort.h"
#include <stdio.h>

/**
 * merge_sort - smerge sort
 * @array:	array to sort
 * @size:	array size
 **/
void merge_sort(int *array, size_t size)
{
	size_t half;
	size_t index;
	int left[2000];
	int right[2000];

	if (!array || size < 2)
	{
		return;
	}
	for (index = 0, half = size / 2; index < half; index++)
	{
		left[index] = array[index];
	}
	for (index = half; index < size; index++)
	{
		right[index - half] = array[index];
	}

	merge_sort(left, half);
	merge_sort(right, size - half);
	helper(array, left, right, size);
}

/**
 * helper - helper
 * @array:	array to sort
 * @l:	left side of the array
 * @r: right side of the array
 * @size:	size of the array
 **/
void helper(int *array, int *l, int *r, size_t size)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int left_size = size / 2;
	int right_size = size - left_size;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, left_size);
	printf("[right]: ");
	print_array(r, right_size);

	while (a < left_size && b < right_size)
	{
		if (l[a] < r[b])
		{
			array[c++] = l[a++];
		}
		else
		{
			array[c++] = r[b++];
		}
	}
	while (a < left_size)
	{
		array[c++] = l[a++];
	}
	while (b < right_size)
	{
		array[c++] = r[b++];
	}
	printf("[Done]: ");
	print_array(array, size);
}
