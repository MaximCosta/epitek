/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** apply_tower
*/

#include "defender.h"

void apply_level(tower_t *tower, game_t *game)
{
    if (game->price[tower->dir][tower->lvl] <= game->money) {
        game->money -= game->price[tower->dir][tower->lvl];
        tower->clvl.left = tower->lvl * 89;
        sfMusic_play(game->mu_upgrade);
        game->tower = 0;
        tower->lvl++;
    }
}
