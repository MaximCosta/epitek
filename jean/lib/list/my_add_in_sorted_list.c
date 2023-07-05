/*
** EPITECH PROJECT, 2021
** Pool Day11
** File description:
** my_add_in_sorted_list
*/

#include <stdlib.h>
#include "mylist.h"

static void placed_insertion(linked_list_t **first, linked_list_t **before,
    linked_list_t **next, void *data)
{
    linked_list_t *node = malloc(sizeof(*node));

    node->next = *next;
    node->data = data;
    if (*before)
        (*before)->next = node;
    else
        *first = node;
}

void my_add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)())
{
    int placed = 0;
    linked_list_t *first = *begin;
    linked_list_t *before = NULL;

    while (*begin && !placed) {
        if ((*cmp)((*begin)->data, data) > 0) {
            placed_insertion(&first, &before, begin, data);
            placed = 1;
        }
        before = *begin;
        *begin = (*begin)->next;
    }
    if (!placed)
        placed_insertion(&first, &before, begin, data);
    *begin = first;
}
