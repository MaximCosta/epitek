/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

void scene_remove_object(list_t **object_list, void *object)
{
    objectany_t *object_any = object_get_any_from_object(object_list, object);

    list_remove(object_list, object_any);
    object_sort(object_list);
}

objectany_t *object_get_any_from_object(list_t **object_list, void *object)
{
    list_t *tmp = *object_list;

    while (tmp) {
        if (CAST(objectany_t *, tmp->value)->object == object)
            return tmp->value;
        tmp = tmp->next;
    }
    return 0;
}
