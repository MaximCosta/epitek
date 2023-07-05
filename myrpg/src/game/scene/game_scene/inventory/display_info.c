/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** display_info.c
*/

#include "../../../../../include/game/rpg.h"

void undisplay_info(game *scene, bool item)
{
    textobject_t *name = textobject_get_from_uuid(&scene->objects, INFO_NAME);
    textobject_t *description = textobject_get_from_uuid(&scene->objects,
    INFO_DESCRIPTION);
    object_t *info = object_get_from_uuid(&scene->objects, INFO);

    if (!item || !scene->player->INVENTORY_O) {
        textobject_set_string(name, "");
        textobject_set_string(description, "");
        object_set_visible(info, false);
    }
}
