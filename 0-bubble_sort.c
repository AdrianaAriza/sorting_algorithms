#include "sort.h"
/**
 *_unsorted - checks if array is unsorted
 *@array: array
 *@size: array size
 *Return: 1-unsorted, 0-sorted
 */
int _unsorted(int *array, size_t size)
{
	size_t i  = 0;

	for (i = 0; i < (size - 1); i++)
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

	if (!array || size <= 0)
		return;
	while (_unsorted(array, size))
	{
		for (i = 0; i < (size - 1) && _unsorted(&array[i], size); i++)
		{
			if (array[i] > array[i + 1])
			{
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
				print_array(array, size);
			}
			else
			{
				;
			}
		}
	}
}
