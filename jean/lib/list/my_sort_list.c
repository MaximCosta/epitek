/*
** EPITECH PROJECT, 2021
** Pool Day11
** File description:
** my_sort_list
*/

#include <stdlib.h>
#include "mylist.h"

static void insertion(linked_list_t **head, void *data)
{
    linked_list_t *node = malloc(sizeof(*node));

    node->data = data;
    node->next = *head;
    *head = node;
}

static void delete_node(linked_list_t **before, linked_list_t **node)
{
    linked_list_t *delete = *node;

    (*before)->next = (*node)->next;
    *node = *before;
    free(delete);
}

static void swap_node(linked_list_t **begin, linked_list_t **node,
    linked_list_t **first, int (*cmp)())
{
    void *data = (*node)->data;

    if ((*cmp)((*begin)->data, data) > 0) {
        delete_node(begin, node);
        insertion(first, data);
        *begin = *first;
    } else
        *begin = (*begin)->next;
}

void my_sort_list(linked_list_t **begin, int (*cmp)())
{
    linked_list_t *first = *begin;
    linked_list_t *next;

    while (*begin && (*begin)->next) {
        next = (*begin)->next;
        swap_node(begin, &next, &first, cmp);
    }
    *begin = first;
}
