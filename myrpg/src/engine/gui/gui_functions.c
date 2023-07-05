/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

void gui_add_object(Gui *gui, object_t *object)
{
    objectany_t *object_any = malloc(sizeof(objectany_t));

    object_any->type = OBJECT;
    object_any->object = object;
    list_insert_end(&gui->objects, object_any);
}

void gui_add_text(Gui *gui, textobject_t *object)
{
    objectany_t *object_any = malloc(sizeof(objectany_t));

    object_any->type = TEXT;
    object_any->object = object;
    list_insert_end(&gui->objects, object_any);
}

bool gui_is_open(uuid_t uuid)
{
    Gui *gui = gui_get_from_uuid(uuid);

    if (!gui || !ENGINE->gui_manager->current_gui)
        return false;
    return gui->uuid == ENGINE->gui_manager->current_gui->uuid;
}
