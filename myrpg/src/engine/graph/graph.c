/*
** EPITECH PROJECT, 2021
** list
** File description:
** list.c
*/
#include "../../../include/engine/engine.h"
#include "stdlib.h"

Graph *graph_create_node(void *value)
{
    Graph *node = malloc(sizeof(Graph));

    if (!node)
        return 0;
    node->value = value;
    node->next = 0;
    return node;
}

void graph_delete(Graph **node)
{
    Graph *list = *node;
    Graph *list_next;

    while (list->next != list)
        list = list->next;
    list->next = 0;
    list = *node;
    while (list) {
        list_next = list->next;
        graph_delete_node(list);
        list = list_next;
    }
    *node = 0;
}

void graph_delete_node(Graph *node)
{
    free(node);
}

void graph_insert_end(Graph **node, void *value)
{
    Graph *list = *node;

    if (!(*node)) {
        *node = graph_create_node(value);
        return;
    }
    while (list != *node)
        list = list->next;
    list->next = graph_create_node(value);
    list->next->next = *node;
}

void graph_delete_last_node(Graph **list)
{
    Graph *node = *list;
    Graph *prev = 0;

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
    prev->next = *list;
}
