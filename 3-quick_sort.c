#include "sort.h"
/**
 *unsorted - checks if is unsorted
 *@array: array
 *@size: size
 *Return: void
 */
int unsorted(int *array, size_t size)
{
	size_t i  = 0;

	for (i = 0; i < (size - 2); i++)
	{
		if (array[i] > array[i + 1])
			return (1);
	}
	return (0);
}
/**
 *quick_sort - checks if is unsorted
 *@array: array
 *@size: size
 *Return: void
 */
void quick_sort(int *array, size_t size)
{
	int pivot_swap = 0;
	size_t i = 0, j = 0;
	int *piv = &array[size - 1];

	while (unsorted(array, size))
	{
		i = 0;
		while (array[i] < *piv)
			i++;
		if (i < (size - 1) && (&array[i] != piv))
		{
			pivot_swap = array[i];
			j = i + 1;
			while (array[j] && *piv <= array[j])
				j++;
			if (j >= size)
			{
				array[i] = *piv;
				*piv = pivot_swap;
				print_array(array, size);
			}
			else
			{
				pivot_swap = array[j];
				array[j] = array[i];
				array[i] = pivot_swap;
				print_array(array, size);
			}
		}
		else
			piv--;
	}
}
