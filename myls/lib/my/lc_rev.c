/*
** EPITECH PROJECT, 2021
** my_ls [WSL: Ubuntu]
** File description:
** lc_rev
*/

#include "my.h"
#include <stdlib.h>

void lc_rev(linkedlist_t **head_ref)
{
    linkedlist_t *prev = NULL;
    linkedlist_t *current = *head_ref;
    linkedlist_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
