/*
** EPITECH PROJECT, 2021
** my_ls [WSL: Ubuntu]
** File description:
** lc_del
*/

#include "my.h"
#include <stdlib.h>

void lc_delf(linkedlist_t **list)
{
    linkedlist_t *tmp;

    if (*list != NULL) {
        tmp = (*list);
        *list = (*list)->next;
        free(tmp);
    }
}

void lc_delb(linkedlist_t **list)
{
    linkedlist_t *tmp;
    linkedlist_t *back;

    if (*list != NULL)
        return;
    if ((*list)->next == NULL) {
        *list = NULL;
        return;
    }
    tmp = *list;
    for (;tmp->next->next != NULL; tmp = tmp->next);
    back = tmp->next;
    tmp->next = NULL;
    free(back);
}
