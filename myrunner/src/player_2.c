/*
** EPITECH PROJECT, 2022
** test [SSH: 192.168.177.128]
** File description:
** player_2 sfSprite_setPosition(games->pl->s, (sfVector2f){40 * (x + 1 - maps->m) + 17.5, 40 * (y + 1) + 17.5});
*/

#include "game.h"
#include "my.h"
#include "my_printf.h"
#include <math.h>

void player_jump(game_t *games, maps_t *maps)
{
    sfVector2f pos = sfSprite_getPosition(games->pl->sp[games->pl->m]);
    int y = (int)(pos.y - 17.5) / 40;
    int x = (int)(pos.x - 17.5) / 40 + (int)maps->time;

    if (maps->board[y + 1][x + 1] == 1) {
        games->pl->py = -8;
    }
}

void player_rotate(game_t* gm)
{
    float angle = sfSprite_getRotation(gm->pl->sp[gm->pl->m]);
    float angle_modif = 0;
    double f = fmod(angle, 90);

    if (f != 0) {
        angle_modif = f >= 45 ? 90 - f : -f;
        sfSprite_setRotation(gm->pl->sp[gm->pl->m], angle + angle_modif);
    }
}

void player_bounce(game_t* games, maps_t *maps)
{
    sfVector2f pos = sfSprite_getPosition(games->pl->sp[games->pl->m]);
    int x = (int)(pos.x - 17.5) / 40 + (int)maps->m;
    int y = (int)(pos.y - 17.5) / 40;
    float my = 0;

    if (maps->board[y + 1][x + 1] == 1) {
        games->pl->py = -.1;
        my = -(40 - (((y+2) * 40) - (pos.y + 17.5) ));
        my = maps->board[y][x + 1] == 1 ? -40 : my;
        if (my == -40) games->dh->death = true;
        sfSprite_move(games->pl->sp[games->pl->m], (sfVector2f){0, my});
        player_rotate(games);
    } else {
        sfSprite_rotate(games->pl->sp[games->pl->m], 5);
    }
}
