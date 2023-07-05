/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** init_game
*/

#include "defender.h"

void init_play(game_t *game)
{
    if (game->towers != NULL)
        free(game->towers);
    sfClock_restart(game->time);
    game->money = 0;
    game->mn->mc.x = 0;
    game->mn->mc.y = 0;
    game->towers = malloc(sizeof(tower_t *) * (game->ctower + 1));
    game->towers[game->ctower] = NULL;
    for (int i = 0; i < game->ctower; i++) {
        game->towers[i] = malloc(sizeof(tower_t));
        game->towers[i]->lvl = 0;
        game->towers[i]->dir = 0;
    }
}

void init_price(game_t *game)
{
    int price[4][4] = {{10, 15, 20, 25}, {15, 20, 25, 30}, {15, 25, 35, 45},
        {20, 25, 30, 35}};
    game->price = malloc(sizeof(int *) * 4);

    for (int i = 0; i < 4; i++) {
        game->price[i] = malloc(sizeof(int) * 4);
        for (int j = 0; j < 4; j++) {
            game->price[i][j] = price[i][j];
        }
    }
}

void init_next(game_t *game, int wx, int wy)
{
    game->mn = malloc(sizeof(menu_t));
    game->asset = malloc(sizeof(asset_t));
    game->mn->np = my_calloc(4UL, 0, FILE / 2);
    game->mn->sp = malloc(sizeof(sfSprite *) * FILE);
    game->mn->tx = malloc(sizeof(sfTexture *) * FILE);
    game->mn->pos = malloc(sizeof(sfVector2f) * FILE);
    game->mn->choice = 0;
    game->sx = (wx / 2) - ((game->lw * game->cell) / 2);
    game->sy = (wy / 2) - ((game->lh * game->cell) / 2);
    init_music(game);
}
