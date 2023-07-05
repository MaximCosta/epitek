/*
** EPITECH PROJECT, 2021
** my_rev_list
** File description:
** echo $?
*/

#include "include/my.h"
#include "include/mylist.h"
#include <stdlib.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *pre = NULL;
    linked_list_t *cur = *begin;
    linked_list_t *nex = NULL;

    while (cur != NULL) {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    *begin = pre;
}
