/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** create_cursor.c
*/

#include "../../../../../include/game/rpg.h"

static const char *CURSOR_LOAD_S = "./assets/main/cursor.png";

void skip_animation(LoadScene *load_scene)
{
    object_t *cursor = object_get_from_uuid(&load_scene->objects, CURSOR_LOAD);
    static DeltaTime delta = (DeltaTime){.saved = 0.00, .time = 0.00};

    if (!load_scene->mouse_press) {
        object_set_rect(cursor, (sfIntRect){32, 0, 48, 48});
    }
    if (load_scene->mouse_press) {
        if (elapsed_time_milliseconds(50, &delta.time, &delta.saved) &&
        object_get_rect(cursor).left < object_get_origin_size(cursor).x
         - 47)
            object_set_rect(cursor, (sfIntRect){object_get_rect(cursor).left
            + 47, 0, 48, 48});
    }
    if (object_get_rect(cursor).left >=
    object_get_origin_size(cursor).x - 47) {
        music_pause(0);
        !load_scene->mouse_press;
        scene_change(MAIN_SCENE);
    }

}

void create_cursor_load(LoadScene *load_scene)
{
    object_t *cursor = malloc(sizeof(object_t));

    scene_add_object(&load_scene->objects, object_create_from_image(
        CURSOR_LOAD, (loc_t){1830, 1002}, CURSOR_LOAD_S
    ));
    cursor = object_get_from_uuid(&load_scene->objects, CURSOR_LOAD);
    object_set_rect(cursor, (sfIntRect){32, 0, 48, 48});
}
