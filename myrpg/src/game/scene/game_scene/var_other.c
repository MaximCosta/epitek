/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** var_other.c
*/

#include "../../../../include/game/rpg.h"

void var_other(game *scene)
{
    scene->quests->on_click = false;
    scene->quests->n_lapis = 0;
    scene->quests->n_emeraude = 0;
    scene->quests->n_redstone = 0;
    scene->game_destroyed = false;
}
