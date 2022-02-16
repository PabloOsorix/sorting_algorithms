#include "sort.h"

/**
 * selection_sort - function that sort an array with
 * the selection sort algorithm.
 * @array: array to sort.
 * @size: of the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	char status = 'N';
	int tmp;

	if (!array || size <= 2)
		return;

	for (i = 0; array && i < size; i++)
	{
		tmp = i;
		for (j = i + 1; array && j < size; j++)
		{
			if (array[j] < array[tmp])
			{
				tmp = j;
				status = 'T';
			}
		}
		if (status != 'T')
			continue;

		if (tmp != array[i])
		{
			j = array[i];
			array[i] = array[tmp];
			array[tmp] = j;
			print_array(array, size);
		}
		status = 'N';
	}
}
