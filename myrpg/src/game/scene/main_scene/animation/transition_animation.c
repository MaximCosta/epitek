/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** transition_animation.c
*/

#include "../../../../../include/game/rpg.h"

void transition_animation(main_scene_t *main_scene)
{
    object_t *black_screen = NULL;
    sfColor actual = sfColor_fromRGBA(255, 255, 255, 0);

    if (!main_scene->transition)
        return;
    black_screen = object_get_from_uuid(&main_scene->objects, BLACKSCREEN);
    actual = sfSprite_getColor(black_screen->sprite);
    actual.a += (0.0005 * ENGINE->delta_time);
    sfSprite_setColor(black_screen->sprite, actual);
    if (actual.a >= 240)
        scene_change(MENU);
}
