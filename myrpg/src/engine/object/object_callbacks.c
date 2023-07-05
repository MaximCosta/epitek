/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

bool object_on_hover(object_t *object,
        void (*on_hover)(object_t *object))
{
    object->on_hover = on_hover;
    if (object->hovered)
        return true;
    else
        return false;
}

bool object_on_unhover(object_t *object,
        void (*on_unhover)(object_t *object))
{
    object->on_unhover = on_unhover;
    if (!object->hovered)
        return true;
    else
        return false;
}

void object_on_click(object_t *object,
        void (*on_click)(object_t *object))
{
    object->on_click = on_click;
}
