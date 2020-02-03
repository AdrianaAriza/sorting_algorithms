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
	int aux = 0, pos;

	for (i = 0; i < size - 3; i++)
	{
		aux = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < aux)
			{
				aux = array[j];
				pos = j;
			}
		}
		array[pos] = array[i];
		array[i] = aux;
		print_array(array, size);
	}
}
