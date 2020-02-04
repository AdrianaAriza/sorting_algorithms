#include "sort.h"
/**
 * counting_sort - Sorts an array in ascending order
 * @array: Array
 * @size: Pointer to the previous element of the list
 * Return: Void
 */
void counting_sort(int *array, size_t size)
{
	int *a, *output, idx, val;
	size_t max, sum = 0, i = 0;

	if (!array || !size)
		return;
	max = array[0];
	while (i < size)
	{
		if (array[i] > (int) max)
			max = array[i];
		i++; }
	a = malloc(sizeof(int) * (max + 1));
	if (!a)
		return;
	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	for (i = 0; i <= max; i++)
		a[i] = 0;
	for (i = 0; i < size; i++)
		a[array[i]] += 1;
	for (i = 0; i <= max; i++)
	{
		if (a[i] == 0)
			a[i] = a[i] + sum;
		else
			sum += a[i], a[i] = sum;
	}
	print_array(a, max + 1);
	for (i = 0; i < size; i++)
	{
		idx = a[array[i]] - 1;
		val = array[i];
		output[idx] = val;
		a[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(a);
	free(output);
}
