/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD04pm-maxim.costa [WSL: Ubuntu]
** File description:
** int_list
*/

#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    if (!*front_ptr) {
        return false;
    }
    if (!(*front_ptr)->next) {
        free(*front_ptr);
        *front_ptr = NULL;
        return true;
    }
    int_node_t *current = *front_ptr;
    while (current->next->next) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return true;
}

bool int_list_del_elem_at_position(
    int_list_t *front_ptr, unsigned int position)
{
    if (!*front_ptr) {
        return false;
    }
    if (position == 0) {
        int_node_t *tmp = *front_ptr;
        *front_ptr = (*front_ptr)->next;
        free(tmp);
        return true;
    }
    int_node_t *current = *front_ptr;
    for (unsigned int i = 0; i < position - 1; i++) {
        if (!current) {
            return false;
        }
        current = current->next;
    }
    int_node_t *tmp = current->next;
    current->next = current->next->next;
    free(tmp);
    return true;
}

void int_list_clear(int_list_t *front_ptr)
{
    while (*front_ptr) {
        int_list_del_elem_at_front(front_ptr);
    }
}