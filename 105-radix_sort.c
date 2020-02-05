#include "sort.h"
/**
 * radix_sort - Sorts an array
 * @array: Array
 * @size: Pointer to the previous element of the list
 * Return: Void
 */
void radix_sort(int *array, size_t size)
{
	int a[10], *output, idx, val, i = 0, mod;
	size_t max, sum = 0;

	if (!array || !size || size < 2)
		return;
	max = array[0];
	while (i < (int)size)
	{
		if (array[i] > (int) max)
			max = array[i];
		i++; }
	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	mod = 1;
	while (max / mod >= 1)
	{
		sum = 0;
		for (i = 0; i <= 9; i++)
			a[i] = 0;
		for (i = 0; i <= 9 ; i++)
			a[array[i] / mod % 10] += 1;
		for (i = 0; i <= 9; i++)
		{
			if (a[i] == 0)
				a[i] = a[i] + sum;
			else
				sum += a[i], a[i] = sum;
		}
		for (i = size - 1; i >= 0; i--)
		{
			idx = a[array[i] / mod % 10] - 1;
			val = array[i];
			output[idx] = val;
			a[array[i] / mod % 10]--; }
		for (i = 0; i < (int)size; i++)
			array[i] = output[i];
		mod = mod * 10;
		print_array(array, size); }
	free(output);
}
