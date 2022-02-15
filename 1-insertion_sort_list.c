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
                    (*list)->next->next->prev = *list;
                    (*list)->next = (*list)->next->next;
                    (*list)->prev = tmp;
                    tmp->next = *list;
                    tmp->prev  = NULL;
                    *list = tmp;
                    head = *list;
                    print_list(head);
                    counter+= 1;
                    *list = (*list)->next;
                    continue;
                }
            }
            if((*list)->n > (*list)->next->n)
            {
                s_tmp = (*list)->next;
                s_tmp->prev = (*list)->prev;
                (*list)->next = (*list)->next->next;
                (*list)->prev->next = s_tmp;
                (*list)->prev = s_tmp;
                s_tmp->next = *list;
                *list = s_tmp;
                print_list(head);
                counter+= 1;
                if ((*list)->prev->n > (*list)->n)
                {
                    while((*list)->n < (*list)->prev->n)
                    {
                        tmp = (*list)->prev;
                        if (tmp->prev != NULL)
                        {
                            tmp->prev->next = *list;
                            (*list)->prev = (*list)->prev->prev;
                            if ((*list)->next != NULL)
                            {
                                tmp->next = (*list)->next;
                                (*list)->next->prev = tmp;
                            }
                            else
                                tmp->next = NULL;
                            (*list)->next = tmp;
                            tmp->prev = *list;
                            print_list(head);

                        }
                        else
                        {
                            tmp->next = (*list)->next;
                            (*list)->next->prev = tmp;
                            tmp->prev = *list;
                            (*list)->prev = NULL;
                            (*list)->next = tmp;
                            head = *list;
                            print_list(head);
                            break;
                        }
                    }

                }
            }
            *list = (*list)->next;
        }
    }
    *list = head;
}