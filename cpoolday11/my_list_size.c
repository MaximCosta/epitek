/*
** EPITECH PROJECT, 2021
** my_list_size
** File description:
** man man
*/

#include "include/my.h"
#include "include/mylist.h"
#include <stdlib.h>

int my_list_size(linked_list_t const *begin)
{
    int i = 0;

    while (begin != NULL) {
        begin = begin->next;
        i++;
    }
    return i;
}
