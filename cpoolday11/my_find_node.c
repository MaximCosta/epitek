/*
** EPITECH PROJECT, 2021
** my_find_node
** File description:
** csfml is the best thing ever
*/

#include "include/my.h"
#include "include/mylist.h"
#include <stdlib.h>

linked_list_t *my_find_node(linked_list_t const *begin, 
        void const *data_ref, int (*cmp)())
{
    linked_list_t *data = (linked_list_t*)begin;

    while (data != NULL) {
        if ((*cmp)(data->data, data_ref) == 0)
            return data;
        data = data->next;
    }
    return 0;
}
