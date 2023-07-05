/*
** EPITECH PROJECT, 2021
** Pool Day11
** File description:
** my_params_to_array
*/

#include <stdlib.h>
#include "mylist.h"

static void insertion(linked_list_t **head, char *str)
{
    linked_list_t *node = malloc(sizeof(*node));

    node->data = str;
    node->next = *head;
    *head = node;
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *head = NULL;

    for (int i = 0; i < ac; i++) {
        insertion(&head, av[i]);
    }
    return head;
}
