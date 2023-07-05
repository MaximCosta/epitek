/*
** EPITECH PROJECT, 2021
** list
** File description:
** list.c
*/
#include "../../../include/engine/engine.h"
#include "stdlib.h"

void list_delete(list_t **node)
{
    list_t *list = *node;
    list_t *list_next;

    while (list) {
        list_next = list->next;
        list_delete_node(list);
        list = list_next;
    }
    *node = 0;
}

void list_delete_node(list_t *node)
{
    free(node);
}

void list_delete_first_node(list_t **list)
{
    list_t *curr = *list;

    if (!curr)
        return;
    *list = curr->next;
    free(curr);
}

void list_delete_last_node(list_t **list)
{
    list_t *node = *list;
    list_t *prev = 0;

    if (!node)
        return;
    if (!node->next) {
        *list = 0;
        return;
    }
    while (node->next) {
        prev = node;
        node = node->next;
    }
    free(node);
    prev->next = 0;
}
