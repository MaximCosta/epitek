/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** list_remove.c
*/

#include "../../../../../include/game/rpg.h"

void list_remove(list_t **list, void *value)
{
    list_t *list_next;
    list_t *tmp;

    if (value == (*list)->value) {
        *list = (*list)->next;
        list_delete_node(*list);
        return;
    }
    list_next = *list;
    while (list_next->next && list_next->next->value != value)
        list_next = list_next->next;
    if (!list_next->next)
        return;
    if (list_next->next->next) {
        tmp = list_next->next;
        list_next->next = list_next->next->next;
        list_delete_node(tmp);
    } else {
        list_delete_node(list_next->next);
        list_next->next = 0;
    }
}
