/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD04pm-maxim.costa [WSL: Ubuntu]
** File description:
** int_list
*/

#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

bool int_list_add_elem_at_position(
    int_list_t *front_ptr, int elem, unsigned int position)
{
    int_node_t *new_node = (int_node_t *) malloc(sizeof(int_node_t));
    if (!new_node) {
        return false;
    }
    new_node->value = elem;
    if (position == 0) {
        new_node->next = *front_ptr;
        *front_ptr = new_node;
        return true;
    }
    int_node_t *current = *front_ptr;
    for (unsigned int i = 0; i < position - 1; i++) {
        if (!current) {
            return false;
        }
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return true;
}

int int_list_get_elem_at_front(int_list_t list)
{
    return list->value;
}

int int_list_get_elem_at_back(int_list_t list)
{
    int_node_t *current = list;
    while (current->next) {
        current = current->next;
    }
    return current->value;
}

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    int_node_t *current = list;
    for (unsigned int i = 0; i < position; i++) {
        if (!current) {
            return 0;
        }
        current = current->next;
    }
    return current->value;
}

bool int_list_del_elem_at_front(int_list_t *front_ptr)
{
    if (!*front_ptr) {
        return false;
    }
    int_node_t *tmp = *front_ptr;
    *front_ptr = (*front_ptr)->next;
    free(tmp);
    return true;
}