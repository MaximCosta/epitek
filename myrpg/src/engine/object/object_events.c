/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

void object_handle_hover_event(object_t *button)
{
    if (object_is_hovered(button)) {
        if (!button->hovered && button->on_hover)
            button->on_hover(button);
        object_set_hovered(button, true);
    } else {
        if (button->hovered && button->on_unhover)
            button->on_unhover(button);
        object_set_hovered(button, false);
    }
}

void object_handle_click_event(object_t *button)
{
    if (button->hovered && button->on_click)
        button->on_click(button);
}

void object_handle_events(list_t *objects, sfEvent *event)
{
    object_t *obj = 0;

    if (!objects)
        return;
    while (objects) {
        obj = object_get_from_any(objects->value);
        if (!object_is_visible(obj)) {
            objects = objects->next;
            continue;
        }
        if (event->type == sfEvtMouseMoved)
            object_handle_hover_event(obj);
        if (event->type == sfEvtMouseButtonReleased)
            object_handle_click_event(obj);
        objects = objects->next;
    }
}

bool object_is_hovered(object_t *object)
{
    sfRenderWindow *window = ENGINE->window;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect float_rect = sfSprite_getGlobalBounds
        (object->sprite);

    return sfFloatRect_contains(&float_rect, mouse_pos.x, mouse_pos.y);
}
