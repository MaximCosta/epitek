/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** add_text.c
*/

#include "../../../../../include/game/rpg.h"

void add_text(game *scene)
{
    scene_add_text(&scene->objects, textobject_create(
        INFO_NAME, (loc_t){0, 0}, ""));
    scene_add_text(&scene->objects, textobject_create(
        INFO_DESCRIPTION, (loc_t){0, 0}, ""));
    object_set_render_priority(textobject_get_from_uuid(&scene->objects,
        INFO_NAME)->object, 211);
    object_set_render_priority(textobject_get_from_uuid(&scene->objects,
        INFO_DESCRIPTION)->object, 212);
}
