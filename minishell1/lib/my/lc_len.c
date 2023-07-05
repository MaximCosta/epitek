/*
** EPITECH PROJECT, 2022
** antman [WSL: Ubuntu]
** File description:
** lc_len
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int lc_len(linkedlist_t *node)
{
    linkedlist_t *tmp = node;
    int i;

    for (i = 0; tmp != NULL; tmp = tmp->next)
        i++;
    return i;
}
