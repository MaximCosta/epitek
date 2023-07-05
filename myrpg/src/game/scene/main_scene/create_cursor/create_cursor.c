/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** create_cursor.c
*/

#include "../../../../../include/game/rpg.h"

static const char *CURSOR_S = "./assets/main/cursor.png";

void create_cursor(main_scene_t *main_scene)
{
    object_t *cursor = malloc(sizeof(object_t));

    scene_add_object(&main_scene->objects, object_create_from_image(
        CURSOR, (loc_t){0, 0}, CURSOR_S
    ));
    cursor = object_get_from_uuid(&main_scene->objects, CURSOR);
    disable_cursor();
    object_set_rect(cursor, (sfIntRect){0, 0, 32, 32});
}
