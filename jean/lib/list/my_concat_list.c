/*
** EPITECH PROJECT, 2021
** Pool Day11
** File description:
** my_concat_list
*/

#include "mylist.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *first = *begin1;
    linked_list_t *last;

    while (*begin1) {
        last = *begin1;
        *begin1 = (*begin1)->next;
    }
    last->next = begin2;
    *begin1 = first;
}
