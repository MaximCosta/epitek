/*
** EPITECH PROJECT, 2021
** Pool Day11
** File description:
** my_merge
*/

#include <stdlib.h>
#include "mylist.h"

void my_merge(linked_list_t **begin1, linked_list_t *begin2, int (*cmp)())
{
    linked_list_t *delete;

    while (begin2) {
        delete = begin2;
        my_add_in_sorted_list(begin1, begin2->data, cmp);
        begin2 = begin2->next;
        free(delete);
    }
}
