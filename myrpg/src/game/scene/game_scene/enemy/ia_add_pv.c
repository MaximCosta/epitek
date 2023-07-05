/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** ia_add_pv.c
*/

#include "../../../../../include/game/rpg.h"

bool delete_enemy(game *scene, mob_t *mob, int id);

bool ia_add_pv(game *scene, mob_t *tmp_sh, mob_t *mobs)
{
    if (scene->toolbar->pv <= scene->player->pv_max - 5)
        scene->toolbar->pv += 5;
    return delete_enemy(scene, tmp_sh, mobs->id);
}
