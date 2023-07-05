/*
** EPITECH PROJECT, 2021
** Pool Day11
** File description:
** my_list_size
*/

#include "mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int cpt = 0;

    while (begin) {
        cpt++;
        begin = begin->next;
    }
    return cpt;
}
