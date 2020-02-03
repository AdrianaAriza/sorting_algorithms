#include "sort.h"
/**
 *shell_sort - sort array
 *@array: array
 *@size: size
 *Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, g = 1;
	int aux;

	while (g < size)
		g = (g * 3) + 1;
	g = (g - 1) / 3;
	for ( ; g > 0; g = (g - 1) / 3)
	{
		for (i = g; i < size; i++)
		{
			aux = array[i];
			for (j = i; j > g && array[j - g] > aux; j = j -  g)
				array[j] = array[j - g];
			array[j] = aux;
		}
		print_array(array, size);
	}
}
