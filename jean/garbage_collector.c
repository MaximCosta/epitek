/*
** EPITECH PROJECT, 2021
** bistro-matic
** File description:
** garbage_collector
*/

#include <stdlib.h>
#include "my_all.h"
#include "bistromatic.h"

char *get(char *val, opbase_t opbase)
{
    create_node(opbase.list, val);
    return val;
}

void free_gc(linked_list_t **list)
{
    linked_list_t *tmp = NULL;

    while (*list) {
        free((*list)->data);
        tmp = (*list)->next;
        free(*list);
        *list = tmp;
    }
}
