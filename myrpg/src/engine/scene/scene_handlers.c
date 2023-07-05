/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"
#include "../../../include/game/rpg.h"

void scene_render(list_t *objects)
{
    object_t *obj = 0;

    while (objects) {
        obj = object_get_from_any(objects->value);
        if (!object_is_visible(obj)) {
            objects = objects->next;
            continue;
        }
        if (CAST(objectany_t *, objects->value)->type == TEXT)
            sfRenderWindow_drawText(ENGINE->window, CAST(textobject_t *, CAST(
                objectany_t *, objects->value)->object)->text, NULL);
        else
            sfRenderWindow_drawSprite(ENGINE->window, obj->sprite, NULL);
        objects = objects->next;
    }
    gui_render(ENGINE->gui_manager->current_gui);
}

void scene_handle_events(list_t *objects, sfEvent *event)
{
    object_t *obj = 0;

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
    if (ENGINE->gui_manager->current_gui)
        object_handle_events(ENGINE->gui_manager->current_gui->objects, event);
}
