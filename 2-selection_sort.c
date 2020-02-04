#include "sort.h"
/**
 *selection_sort - sort array
 *@array: array to sort
 *@size: array size
 *Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int aux = 0, pos, f = 0;

	if (!array || !size)
	{
		return;
	}
	for (i = 0; i < size - 2; i++)
	{
		aux = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < aux)
			{
				aux = array[j];
				pos = j;
				f = 1;
			}
		}
		if (f && array[j] >aux)
		{
		array[pos] = array[i];
		array[i] = aux;
		print_array(array, size);
		f = 0;
		}
	}
}
