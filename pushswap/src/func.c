/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-maxim.costa [WSL: Ubuntu]
** File description:
** func
*/

#include "../push.h"

linkedlist_t *create_node(int value)
{
    linkedlist_t *list = malloc(sizeof(linkedlist_t));

    if (list == NULL)
        return NULL;
    list->data = value;
    list->next = NULL;
    return list;
}

void add_node_at_back(int data, linkedlist_t **node)
{
    linkedlist_t *tmp = *node;

    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = create_node(data);
}

void add_node_at_front(int data, linkedlist_t **node)
{
    linkedlist_t *tmp = create_node(data);

    tmp->next = *node;
    *node = tmp;
}

void delete_first_node(linkedlist_t **list)
{
    linkedlist_t *tmp;

    if (*list != NULL) {
        tmp = (*list);
        *list = (*list)->next;
        free(tmp);
    }
}
