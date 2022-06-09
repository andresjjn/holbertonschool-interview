#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void helper(int *array, int *l, int *r, size_t size);

#endif
