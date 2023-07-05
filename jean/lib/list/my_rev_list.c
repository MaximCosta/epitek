/*
** EPITECH PROJECT, 2021
** Pool Day11
** File description:
** my_rev_list
*/

#include <stdlib.h>
#include "mylist.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *current = *begin;
    linked_list_t *before = NULL;
    linked_list_t *next;

    while (current != NULL) {
        next = current->next;
        current->next = before;
        before = current;
        current = next;
    }
    *begin = before;
}
