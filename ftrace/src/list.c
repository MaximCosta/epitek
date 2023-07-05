/*
** EPITECH PROJECT, 2023
** B_PSU_400_MPL_4_1_FTRACE_HUGO_ESCHLIMANN_LIST_C
** File description:
** list
*/

#include "../include/ftrace.h"

bool list_add_elem_at_back(nm_list_t **list, char *name, int64_t address)
{
    nm_list_t *current = NULL;
    nm_list_t *new_node = malloc(sizeof(nm_list_t));

    if (!new_node) {
        return false;
    }
    new_node->next = NULL;
    new_node->name = name;
    new_node->address = address;
    if (list_is_empty(*list)) {
        *list = new_node;
    } else {
        current = *list;
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
    }
    return true;
}

bool list_is_empty(nm_list_t *list)
{
    if (list == NULL)
        return true;
    return false;
}

void list_clear(nm_list_t **list)
{
    nm_list_t *current = *list;
    nm_list_t *next = NULL;

    while (current != NULL) {
        next = current;
        current = current->next;
        free(next);
    }
    *list = NULL;
}

void list_dump(nm_list_t *list)
{
    for (; list != NULL; list = list->next) {
        printf("%016lx %s\n", list->address, list->name);
    }
}
