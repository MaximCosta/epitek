/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** particles_animation.c
*/

#include "../../../../../include/game/rpg.h"

void particles_animation(main_scene_t *main_scene)
{
    object_t *particles = object_get_from_uuid(&main_scene->objects, PARTICLES);
    sfColor color = sfColor_fromRGBA(255, 255, 255, 255);

    if (object_get_position(particles).x >= 0)
        object_set_position(particles, (sfVector2f){0 - (
            object_get_origin_size(particles).x / 2), 0});
    else
        object_set_position(particles, (sfVector2f){
            object_get_position(particles).x + (0.00005 *
            ENGINE->delta_time), 0
        });
    sfSprite_setColor(particles->sprite, color);
}
