/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** path.c
*/

#include "../../../../../include/game/rpg.h"

void move_rect_2(SwitchScene *scene, float time, int *path, object_t *cursor)
{
    if (*path == 1) {
        if (object_get_rect(cursor).left > 32)
            object_set_rect(cursor, (sfIntRect){object_get_rect(cursor).left
            - 47, 0, 48, 48});
        else {
            object_set_scale(cursor, (sfVector2f){object_get_scale(cursor).x
            * (-1), 1});
            *path = 0;
        }
    }
}

void move_rect(SwitchScene *scene)
{
    static DeltaTime delta = (DeltaTime){.saved = 0.00, .time = 0.00};
    object_t *cursor = object_get_from_uuid(&scene->objects, SWITCH_CURSOR);
    static int path = 0;

    if (!elapsed_time_milliseconds(50, &delta.time, &delta.saved))
        return;

    if (path == 0) {
        if (object_get_rect(cursor).left < object_get_origin_size(cursor).x
        - 47)
            object_set_rect(cursor, (sfIntRect){object_get_rect(cursor).left
            + 47, 0, 48, 48});
        else {
            object_set_scale(cursor, (sfVector2f){object_get_scale(cursor).x
            * (-1), 1});
            path = 1;
        }
    }
    move_rect_2(scene, delta.time, &path, cursor);
}
