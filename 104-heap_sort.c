#include "sort.h"

/**
 * siftdown - fixes a heap
 * @arr: the heap to fix
 * @source: the root of the heap
 * @tail: the last index of the heap
 * @size: size of the array
 * Return: void
 */
void siftdown(int *arr, size_t source, size_t tail, size_t size)
{
	size_t l_child, r_child, swapper;
	int tmp;

	while ((l_child = (2 * source) + 1) <= tail)
	{
		swapper = source;
		r_child = l_child + 1;
		if (arr[swapper] < arr[l_child])
			swapper = l_child;
		if (r_child <= tail && arr[swapper] < arr[r_child])
			swapper = r_child;
		if (swapper == source)
			return;
		tmp = arr[source];
		arr[source] = arr[swapper];
		arr[swapper] = tmp;
		print_array(arr, size);
		source = swapper;
	}
}

/**
 * n_heap - makes a new heap
 * @arr: array
 * @size: size
 *
 * Return: void
 */
void n_heap(int *arr, size_t size)
{
	size_t new_h;

	for (new_h = ((size - 1) - 1) / 2; 1; new_h--)
	{
		siftdown(arr, new_h, size - 1, size);
		if (new_h == 0)
			break;
	}
}

/**
 * heap_sort - sorts an array of integers
 * in ascending order using the Heap sort algorithm
 * @array: array
 * @size: size
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t tail;
	int tmp;

	if (array == NULL || size < 2)
		return;
	n_heap(array, size);
	tail = size - 1;
	while (tail > 0)
	{
		tmp = array[tail];
		array[tail] = array[0];
		array[0] = tmp;
		print_array(array, size);
		tail--;
		siftdown(array, 0, tail, size);
	}
}
