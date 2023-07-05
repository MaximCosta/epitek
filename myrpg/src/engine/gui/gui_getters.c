/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

Gui *gui_get_from_uuid(uuid_t uuid)
{
    list_t *gui = ENGINE->gui_manager->guis;

    while (gui) {
        if (((Gui *)gui->value)->uuid == uuid)
            return gui->value;
        gui = gui->next;
    }
    return 0;
}
