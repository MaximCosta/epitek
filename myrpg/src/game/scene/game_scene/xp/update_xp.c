/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** update_xp.c
*/

#include "../../../../../include/game/rpg.h"

void resize_xp(game *scene, float state_scale, sfVector2f xpscale,
object_t *xp_bar)
{
    if (xpscale.x < state_scale)
        object_set_scale(xp_bar, (sfVector2f){xpscale.x + (
            0.0000003 * ENGINE->delta_time), 1});
    if (xpscale.x > state_scale)
        object_set_scale(xp_bar, (sfVector2f){xpscale.x - (
            0.0000003 * ENGINE->delta_time), 1});
}

void update_xp(game *scene)
{
    object_t *xp_bar = object_get_from_uuid(&scene->objects, TOOLXP_FRONT);
    textobject_t *level = textobject_get_from_uuid(
        &scene->objects, PLAYER_LVL_TEXT);
    sfVector2f xpscale = {0};
    float new_scale = 0.00;
    float first = (float)((float)scene->player->xp * (float)100.00);
    first = (float)((float)first / (float)scene->player->xp_max);
    new_scale = (float)((float)first / (float)100.00);

    xpscale = object_get_scale(xp_bar);
    resize_xp(scene, new_scale, xpscale, xp_bar);
    if (xpscale.x >= 1) {
        scene->player->xp -= scene->player->xp_max;
        scene->player->xp_max *= 1.2;
        scene->player->lvl += 1;
        scene->stats->dolex += 1;
        object_set_scale(xp_bar, (sfVector2f){0, 1});
        textobject_set_string(level, my_strcat("Level : ", my_itoa(
            scene->player->lvl, 0)));
    }
}
