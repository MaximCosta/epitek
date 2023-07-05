/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD04pm-maxim.costa [WSL: Ubuntu]
** File description:
** int_list
*/

#include "int_list.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int int_list_get_size(int_list_t list)
{
    unsigned int size = 0;
    int_node_t *current = list;
    while (current) {
        current = current->next;
        size++;
    }
    return size;
}

bool int_list_is_empty(int_list_t list)
{
    return list == NULL;
}

void int_list_dump(int_list_t list)
{
    int_node_t *current = list;
    while (current) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_node_t *new_node = (int_node_t *) malloc(sizeof(int_node_t));
    if (!new_node) {
        return false;
    }
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return true;
}

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_node_t *new_node = (int_node_t *) malloc(sizeof(int_node_t));
    if (!new_node) {
        return false;
    }
    new_node->value = elem;
    new_node->next = NULL;
    if (!*front_ptr) {
        *front_ptr = new_node;
        return true;
    }
    int_node_t *current = *front_ptr;
    while (current->next) {
        current = current->next;
    }
    current->next = new_node;
    return true;
}
