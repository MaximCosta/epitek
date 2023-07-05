/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

void object_set_visible(object_t *object, bool visible)
{
    object->visible = visible;
}

bool object_is_visible(object_t *object)
{
    return object->visible;
}

void object_set_hovered(object_t *object, bool hovered)
{
    object->hovered = hovered;
}

void object_set_render_priority(object_t *object, short priority)
{
    object->render_priority = priority;
}
