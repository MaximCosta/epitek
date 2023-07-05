/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"
#include "../../../include/game/rpg.h"

Gui *gui_create(uuid_t uuid, object_t *gui_object)
{
    Gui *gui = malloc(sizeof(Gui));

    gui->uuid = uuid;
    gui->objects = 0;
    gui->gui_object = gui_object;
    return gui;
}

void gui_register(Gui *gui)
{
    list_insert_first(&ENGINE->gui_manager->guis, gui);
}

void gui_open(uuid_t uuid)
{
    ENGINE->gui_manager->current_gui = gui_get_from_uuid(uuid);
}

void gui_close(void)
{
    ENGINE->gui_manager->current_gui = 0;
}

void gui_render(Gui *gui)
{
    list_t *object = gui ? gui->objects : 0;
    object_t *obj = 0;

    if (!gui)
        return;
    sfRenderWindow_drawSprite(ENGINE->window, gui->gui_object->sprite, NULL);
    if (!gui->objects)
        return;
    while (object) {
        obj = object_get_from_any(object->value);
        if (!object_is_visible(obj)) {
            object = object->next;
            continue;
        }
        if (CAST(objectany_t *, object->value)->type == TEXT)
            sfRenderWindow_drawText(ENGINE->window, CAST(textobject_t *, CAST(
                objectany_t *, object->value)->object)->text, NULL);
        else
            sfRenderWindow_drawSprite(ENGINE->window, obj->sprite, NULL);
        object = object->next;
    }
}
