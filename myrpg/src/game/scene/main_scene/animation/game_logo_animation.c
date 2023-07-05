/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** game_logo_animation.c
*/

#include "../../../../../include/game/rpg.h"

void game_logo_animation(main_scene_t *main_scene)
{
    object_t *game_logo = object_get_from_uuid(&main_scene->objects, GAME_LOGO);
    static int path = 0;
    float speed = 0.00001;

    if (path == 0)
        object_set_position(game_logo, (sfVector2f){
            object_get_position(game_logo).x, object_get_position(
            game_logo).y - (speed * ENGINE->delta_time)});
    if (object_get_position(game_logo).y < 930 && path == 0)
        path = 1;
    if (path == 1)
        object_set_position(game_logo, (sfVector2f){
            object_get_position(game_logo).x, object_get_position(
            game_logo).y + (speed * ENGINE->delta_time)});
    if (object_get_position(game_logo).y > 950 && path == 1)
        path = 0;
}
