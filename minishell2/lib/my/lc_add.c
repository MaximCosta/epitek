/*
** EPITECH PROJECT, 2021
** my_ls [WSL: Ubuntu]
** File description:
** lc_addf
*/

#include "my.h"
#include <stdlib.h>

void lc_addf(void *data, linkedlist_t **node)
{
    linkedlist_t *tmp = lc_create(data);
    tmp->next = *node;
    *node = tmp;
}

void lc_addb(void *data, linkedlist_t **node)
{
    if (*node) {
        linkedlist_t *tmp = *node;
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = lc_create(data);
    } else {
        *node = lc_create(data);
    }
}
