/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** init_mob.c
*/

#include "../../../../../include/game/rpg.h"

void init_mob(game *scene, object_t *mob)
{
    object_set_rect(mob, (sfIntRect){256, 0, 128, 64});
    object_set_origin(mob, (sfVector2f){64, 64});
}
