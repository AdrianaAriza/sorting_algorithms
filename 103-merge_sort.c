#include"sort.h"
/**
 *merge_sort - sort array
 *@array: array
 *@size: array size
 *Return: void
 */
void merge_sort(int *array, size_t size)
{
	int n_size = 0, sr, sl, n, aux, j;

	if (size < 2)
		return;
	if (size > 2)
	{
		n_size = size / 2;
		merge_sort(array, n_size);
		merge_sort(&array[n_size], size - n_size);
		for (n = size - 1; n > 0; n--)
		{
			j = 0;
			while (j < n && array[n] >= array[j])
				j++;
			if (array[j] != array[n])
			{
				aux = array[n];
				array[n++] = array[j];
				array[j] = aux; } }
		printf("[Done]: ");
		print_array(array, size); }
	if (size > 1)
	{
		sr = size / 2;
		sl = size - (size / 2);
		printf("Merging...\n");
		printf("[left]: ");
		print_array(array, sr);
		printf("[right]: ");
		print_array(&array[sr], sl); }
	if (size == 2)
	{
		if (array[0] > array[1])
		{
			aux = array[1];
			array[1] = array[0];
			array[0] = aux;	}
		printf("[Done]: ");
		print_array(array, size); }
}
