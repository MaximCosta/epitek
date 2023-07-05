/*
** EPITECH PROJECT, 2021
** list
** File description:
** list.c
*/
#include "../../include/common.h"

int list_size(list_t *node)
{
    int i = 1;

    if (!node)
        return 0;
    while (node->next) {
        i++;
        node = node->next;
    }
    return i;
}

void *list_select_random(list_t **node)
{
    list_t *nod = *node;
    int size = list_size(nod);
    int random = rand() % size;

    if (!nod)
        return 0;
    for (int i = 0; i < random; i++)
        nod = nod->next;
    if (!nod)
        nod = *node;
    return nod->value;
}
