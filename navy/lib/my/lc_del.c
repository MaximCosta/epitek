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
    if (*list != NULL) {
        linkedlist_t *tmp = (*list);
        *list = (*list)->next;
        free(tmp);
    }
}

void lc_delb(linkedlist_t **list)
{
    if (*list != NULL) {
        if ((*list)->next == NULL) {
            *list = NULL;
        } else {
            linkedlist_t *tmp = *list;
            for (;tmp->next->next != NULL; tmp = tmp->next);
            linkedlist_t *back = tmp->next;
            tmp->next = NULL;
            free(back);
        }
    }
}
