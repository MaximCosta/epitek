/*
** EPITECH PROJECT, 2021
** my_params_to_list
** File description:
** there's a problem: the intra is not down
*/

#include "include/my.h"
#include "include/mylist.h"
#include <stdlib.h>

int insert_elt(linked_list_t **list, char *elt)
{
    linked_list_t *elm = malloc(sizeof(*elm));

    if (elm == NULL)
        return 84;
    elm->data = elt;
    elm->next = *list;
    *list = elm;
    return 0;
}

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    linked_list_t *datas = 0;

    for (int i = 0; i < ac; i++)
        insert_elt(&datas, av[i]);
    return datas;
}
