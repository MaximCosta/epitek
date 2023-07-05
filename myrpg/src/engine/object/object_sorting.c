/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

static void swap(list_t *list, list_t *next)
{
    void *tmp = list->value;

    if (object_get_from_any(list->value)->render_priority >
        object_get_from_any(list->next->value)->render_priority) {
        list->value = next->value;
        next->value = tmp;
    }
}

void object_sort(list_t **objects)
{
    list_t *list = *objects;
    int len = list_size(*objects);

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            swap(list, list->next);
            list = list->next;
        }
        list = *objects;
    }
}
