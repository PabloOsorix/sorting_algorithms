#include "sort.h"

/**
 * insertion_sort_list - unction that sorts
 * a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: double linked list to sort
 * Return - None is void
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *tmp = NULL, *s_tmp = NULL,*head = NULL;
    int counter = 1;
    head = malloc(sizeof(listint_t));
    tmp = malloc(sizeof(listint_t));
    s_tmp = malloc(sizeof(listint_t));
    if (!tmp || !head)
        return;

    if ((!list || !(*list)->n))
        return;

    head = *list;
    while(counter != 0)
    {
        counter = 0;
        for (;(*list)->next != NULL;)
        {
            if ((*list)->next != NULL && (*list)->prev == NULL)
            {
                if((*list)->n > (*list)->next->n)
                {
                    tmp = (*list)->next;
                    (*list)->next = (*list)->next->next;
                    (*list)->prev = tmp;
                    tmp->next = *list;
                    /*list = tmp;*/
                    print_list(head);
                    counter+= 1;
                    *list = (*list)->next;
                    continue;
                }
            }
            if((*list)->n > (*list)->next->n)
            {
                s_tmp = (*list)->next;
                (*list)->next = (*list)->next->next;
                (*list)->prev = tmp;
                s_tmp->prev = (*list)->prev;
                s_tmp->next = *list;
                /*list = tmp;*/
                /*(*list)->prev = s_tmp;*/
                print_list(head);
                counter+= 1;
            }
            /**else if((*list)->prev != NULL && counter != 0);
            {
                while((*list)->prev->n < (*list)->n)
                {
                    tmp = (*list)->prev;
                    (*list)->prev = (*list)->prev->prev;
                    (*list)->next = tmp;
                    tmp->prev = *list;
                    *list = tmp;
                    print_list(*list);
                    *list = (*list)->prev;
                    continue;
                }
            }*/
            *list = (*list)->next;
        }
        /*list = (*list)->next;*/


    }
}