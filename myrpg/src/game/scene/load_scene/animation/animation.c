/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** animation.c
*/

#include "../../../../../include/game/rpg.h"

void get_path(int path, object_t *load_background, float speed)
{
    if (path == 0)
        object_set_scale(load_background,
            (sfVector2f){object_get_scale(load_background).x
                    - (speed * ENGINE->delta_time),
                object_get_scale(load_background).y
                    - (speed * ENGINE->delta_time)});
    if (path == 1)
        object_set_scale(load_background,
            (sfVector2f){object_get_scale(load_background).x
                    + (speed * ENGINE->delta_time),
                object_get_scale(load_background).y
                    + (speed * ENGINE->delta_time)});
}

void selecte_path(int *path, object_t *load_background, float speed)
{
    if (object_get_scale(load_background).x > 1.25 && *path == 1) {
        object_set_rect(load_background,
            (sfIntRect){
                object_get_rect(load_background).left + 1920, 0, 1920, 1080});
        *path = 0;
    }
    if (object_get_scale(load_background).x < 1 && *path == 0) {
        object_set_rect(load_background,
            (sfIntRect){
                object_get_rect(load_background).left + 1920, 0, 1920, 1080});
        *path = 1;
    }
}
