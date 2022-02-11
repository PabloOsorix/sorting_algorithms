#include "sort.h"

/**
 *bubble_sort - Function  that sorts an array of integers
 *in ascending order using the Bubble sort algorithm.
 *@array: array to sort with the algorithm.
 *@size: size of the array
 *Return - None, function is void
 */

void bubble_sort(int *array, size_t size)
{
    size_t i;
    int tmp = 0;
    int counter = 1;

    if (array == NULL || size == 0)
        return;

    while(counter != 0)
    {   
        counter = 0;
        for (i = 0; array && i < size; ++i)
        {
            
            if (array[i] < array[i - 1])
            {
                counter+= 1;
                tmp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = tmp;
                
                print_array(array, size);
            }
            else
                continue;
        }
    }
}