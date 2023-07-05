/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** destroy
*/

#include "defender.h"

void free_all(game_t *game)
{
    for (int y = 0; y < game->lh; free(game->maps[y++])) {};
    for (int x = 0; x < 4; free(game->price[x++])) {};
    if (game->towers != NULL) {
        for (int i = 0; i < game->ctower; free(game->towers[i]));
        free(game->towers);
    }
    free(game->mn->sp);
    free(game->mn->pos);
    free(game->mn->tx);
    free(game->mn->np);
    free(game->price);
    free(game->asset);
    free(game->maps);
    free(game->mn);
    free(game);
}

void destroy_all2(game_t *game)
{
    sfMusic_destroy(game->mu_upgrade);
    sfMusic_destroy(game->mu_craft);
    sfMusic_destroy(game->mu_loop);
    sfClock_destroy(game->clock);
    sfTexture_destroy(game->btx);
    sfSprite_destroy(game->bsp);
    sfClock_destroy(game->time);
    sfRenderWindow_destroy(game->wd);
    free_all(game);
}

void destroy_all(game_t *game)
{
    for (int i = 0; i < FILE; i++) {
        sfSprite_destroy(game->mn->sp[i]);
        sfTexture_destroy(game->mn->tx[i]);
    }
    sfTexture_destroy(game->asset->tx);
    sfSprite_destroy(game->asset->sp);
    sfTexture_destroy(game->mn->mtx);
    sfTexture_destroy(game->mn->itx);
    sfSprite_destroy(game->mn->msp);
    sfSprite_destroy(game->mn->isp);
    sfFont_destroy(game->mn->font);
    sfText_destroy(game->mn->text);
    destroy_all2(game);
}
