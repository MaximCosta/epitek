/*
** EPITECH PROJECT, 2021
** Pool Day11
** File description:
** my_delete_nodes
*/

#include <stdlib.h>
#include "mylist.h"

static void delete_node(linked_list_t **first,
    linked_list_t **before, linked_list_t **node)
{
    linked_list_t *delete = *node;

    if (*before == NULL) {
        *first = (*node)->next;
        *node = *first;
    } else {
        (*before)->next = (*node)->next;
        *node = *before;
    }
    free(delete);
}

int my_delete_nodes(linked_list_t **begin, void const *data_ref,
    int (*cmp)())
{
    linked_list_t *first = *begin;
    linked_list_t *before = NULL;

    while (*begin) {
        if ((*cmp)((*begin)->data, data_ref) == 0) {
            delete_node(&first, &before, begin);
        } else if (*begin) {
            before = *begin;
            *begin = (*begin)->next;
        }
    }
    *begin = first;
    return 0;
}
