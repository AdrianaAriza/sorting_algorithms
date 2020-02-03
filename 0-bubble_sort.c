#include "sort.h"
/**
 *unsorted - checks if array is unsorted
 *@array: array
 *@size: array size
 *Return: 1-unsorted, 0-sorted
 */
int unsorted(int *array, size_t size)
{
	int i  = 0;

	for (i = 0; i < (size - 2); i++)
	{
		if (array[i] > array[i + 1])
			return (1);
	}
	return (0);
}
/**
 *bubble_sort - sort array
 *@array: array
 *@size: array size
 *Return: 1-unsorted, 0-sorted
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int aux = 0;

	while (_unsorted(array, size))
	{
		for (i = 0; i < (size - 1) && _unsorted(&array[i]); i++)
		{
			if (array[i] > array[i + 1])
			{
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
				print_array(array, size);
			}
			else
				;
		}
	}
}
