/*
** EPITECH PROJECT, 2021
** my_ls [WSL: Ubuntu]
** File description:
** lc_create
*/

#include "my.h"
#include <stdlib.h>

linkedlist_t *lc_create(void *value)
{
    linkedlist_t *list = malloc(sizeof(linkedlist_t));

    if (list == NULL)
        return NULL;
    list->data = value;
    list->next = NULL;
    return list;
}
