/*
** EPITECH PROJECT, 2021
** my_delete_nodes
** File description:
** 01100010 01101001 01101110 01100001 01110010 01111001
*/

#include "include/my.h"
#include "include/mylist.h"
#include <stdlib.h>

void my_delete_node(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *sav = *begin;
    linked_list_t *prev;

    if (sav != NULL && (*cmp)(sav->data, data_ref)) {
        *sav = *sav->next;
        free(sav);
        return;
    }
    while (sav != NULL && (*cmp)(sav->data, data_ref)) {
        prev = sav;
        sav = sav->next;
    }
    if (sav == NULL)
        return;
    prev->next = sav->next;
    free(sav);
}

int find_element(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *sav = *begin;
    while (begin != NULL) {
        if ((*cmp)(sav->data, data_ref))
            return 1;
    }
    return 0;
}

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    while (find_element(begin, data_ref, cmp)) {
        my_delete_node(begin, data_ref, cmp);
    }
    return 0;
}


