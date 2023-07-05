/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** visible.c
*/

#include "../../../../../include/game/rpg.h"

void check_equiped(game *scene, int i, bool to)
{
    if (i < 5) {
        object_set_visible(scene->equiped[i].box, to);
        if (scene->equiped[i].item != NULL)
            object_set_visible(scene->equiped[i].item, to);
    }
}

void set_visible(object_t *inventory_o, game *scene)
{
    object_set_visible(inventory_o, true);
    for (int i = 0; i != 32; i++) {
        if (i < 5) {
            check_equiped(scene, i, true);
            object_set_visible(scene->equiped[i].box, true);
            if (scene->equiped[i].item != NULL)
                object_set_visible(scene->equiped[i].item, true);
        }
        object_set_visible(scene->cases[i].box, true);
        if (scene->cases[i].item != NULL)
            object_set_visible(scene->cases[i].item, true);
    }
}

void set_unvisible(game *scene, object_t *inventory_o)
{
    object_t *info = object_get_from_uuid(&scene->objects, INFO);

    object_set_visible(inventory_o, false);
    object_set_visible(info, false);
    for (int i = 0; i != 32; i++) {
        if (i < 5) {
            check_equiped(scene, i, false);
            object_set_visible(scene->equiped[i].box, false);
            textobject_set_string(scene->equiped[i].info.name_text, "");
        }
        object_set_visible(scene->cases[i].box, false);
        if (scene->cases[i].item != NULL)
            object_set_visible(scene->cases[i].item, false);
    }
}

void visible(
    game *scene, object_t *inventory_o, object_t *player, object_t *case_o)
{
    if (scene->player->INVENTORY_O)
        set_visible(inventory_o, scene);
    else
        set_unvisible(scene, inventory_o);
}
