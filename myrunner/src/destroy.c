/*
** EPITECH PROJECT, 2022
** test [SSH: 192.168.177.128]
** File description:
** destroy
*/

#include "game.h"
#include "my.h"
#include "my_printf.h"

void destroy_loop(game_t *games, maps_t *maps)
{
    int g[17] = {0, 1, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 17, 21, 22, -1};

    for (int i = 0; i < 2; i++) {
        sfSprite_destroy(games->sp_back[i]);
        sfTexture_destroy(games->back[i]);
    }
    for (int i = 0; i < 7; i++) {
        sfTexture_destroy(games->pl->tx[i]);
        sfSprite_destroy(games->pl->sp[i]);
    }
    for (int i = 0; g[i] != -1; i++) {
        sfSprite_destroy(games->sp_ground[g[i]]);
        sfTexture_destroy(games->ground[g[i]]);
    }
    destroy_all(games, maps);
}

void destroy_all(game_t *games, maps_t *maps)
{
    sfTexture_destroy(games->dh->t);
    sfSprite_destroy(games->dh->s);
    sfText_destroy(games->dh->text);
    sfMusic_destroy(games->dh->music);
    sfText_destroy(games->sc->text);
    sfFont_destroy(games->sc->font);
    sfMusic_destroy(games->music);
    sfClock_destroy(games->clock);
    sfRenderWindow_destroy(games->window);
    free_all(games, maps);
}

void free_all(game_t *games, maps_t *maps)
{
    for (int i = 0; i < maps->h; free(maps->board[i++]));
    free(games->pl->tx);
    free(games->pl->sp);
    free(games->pl);
    free(games->sp_ground);
    free(games->ground);
    free(games->sp_back);
    free(games->back);
    free(games->sc);
    free(games->dh);
    free(games);
    free(maps);
}
