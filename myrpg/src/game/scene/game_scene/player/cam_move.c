/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** cam_move.c
*/

#include "../../../../../include/game/rpg.h"

void map_calc(game *scene, sfVector2f *p_pos, object_t *map, object_t *player)
{
    *p_pos = object_get_position(map);
    (*p_pos).y -= 50;
    *p_pos = (sfVector2f){(3200 - ((*p_pos).x + 3200) +
    (object_get_position(player).x)) / 32, (3200 - ((*p_pos).y + 3200)
    + (object_get_position(player).y)) / 32};
}
