/*
** EPITECH PROJECT, 2021
** my_apply_on_nodes
** File description:
** vim-epitech made by x4m3
*/

#include "include/my.h"
#include "include/mylist.h"
#include <stdlib.h>

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void*))
{
    while (begin != NULL) {
        (*f)(begin->data);
        begin = begin->next;
    }
    return 0;
}
