/*
** EPITECH PROJECT, 2021
** My lib list
** File description:
** create_node
*/

#include <stdlib.h>
#include "mylist.h"

void create_node(linked_list_t **head, void *data)
{
    linked_list_t *node = malloc(sizeof(*node));

    node->data = data;
    node->next = *head;
    *head = node;
}
