/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** update_mouse.c
*/

#include "../../../../include/game/rpg.h"

void update_mouse(game *scene)
{
    object_t *cursor_state = object_get_from_uuid(&scene->objects, MOUSE_STATE);
    object_t *mouse = object_get_from_uuid(&scene->objects, CURSOR_GAME);

    object_set_position(object_get_from_uuid(&scene->objects,
    CURSOR_GAME), (sfVector2f) {sfMouse_getPositionRenderWindow(
    ENGINE->window).x, sfMouse_getPositionRenderWindow(ENGINE->window).y});

    if (!scene->player->INVENTORY_O)
        object_set_rect(mouse, (sfIntRect){0, 0, 32, 32});
    if (scene->player->PAUSE)
        object_set_visible(mouse, true);
    else
        object_set_visible(mouse, false);
    if (object_is_visible(mouse))
        object_set_rect(cursor_state, (sfIntRect){0, 0, 80, 30});
    else
        object_set_rect(cursor_state, (sfIntRect){80, 0, 80, 30});
}
