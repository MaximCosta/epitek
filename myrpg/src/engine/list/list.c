/*
** EPITECH PROJECT, 2021
** list
** File description:
** list.c
*/
#include "../../../include/engine/engine.h"
#include "stdlib.h"

list_t *list_create_node(void *value)
{
    list_t *node = malloc(sizeof(list_t));

    if (!node)
        return 0;
    node->value = value;
    node->next = 0;
    return node;
}

void list_insert_first(list_t **node, void *value)
{
    list_t *first_node = *node;

    *node = list_create_node(value);
    if (!(*node))
        *node = first_node;
    else
        (*node)->next = first_node;
}

list_t *list_insert_end(list_t **node, void *value)
{
    list_t *list = *node;

    if (!(*node)) {
        *node = list_create_node(value);
        return *node;
    }
    while (list->next)
        list = list->next;
    list->next = list_create_node(value);
    return list->next;
}
