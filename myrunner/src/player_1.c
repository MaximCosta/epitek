/*
** EPITECH PROJECT, 2022
** test [SSH: 192.168.177.128]
** File description:
** player_1
*/

#include "game.h"
#include "my.h"
#include "my_printf.h"

void init_player_variables(game_t *games, int nb)
{
    games->pl = malloc(sizeof(player_t));
    games->pl->tx = malloc(sizeof(sfTexture*) * nb);
    games->pl->sp = malloc(sizeof(sfSprite*) * nb);
    games->pl->jump = 0;
    games->pl->px = 0;
    games->pl->py = 0;
    games->pl->m = 6;
}

void init_player(game_t *games, maps_t *maps)
{
    char path[60] = {1};
    char buf[3] = {0};
    int nb = 7;

    init_player_variables(games, nb);
    for (int i = 0; i < nb; i++) {
        for (int j = 0; j <= 60; path[j++] = 0);
        games->pl->sp[i] = sfSprite_create();
        my_strcat(path, "./assets/images/players/player-");
        my_itoa(i, buf, 10);
        my_strcat(path, buf);
        my_strcat(path, ".png");
        games->pl->tx[i] = sfTexture_createFromFile(path, NULL);
        sfSprite_setTexture(games->pl->sp[i], games->pl->tx[i], sfTrue);
        sfSprite_setOrigin(games->pl->sp[i], (sfVector2f){17.5, 17.5});
        sfSprite_setPosition(games->pl->sp[i], maps->start);
    }
}

void player_render(game_t* gm)
{
    sfRenderWindow_drawSprite(gm->window, gm->pl->sp[gm->pl->m], NULL);
}

void player_controller(game_t *gm, maps_t *maps)
{
    sfVector2f pos;
    int speed = maps->time - maps->m == 0 ? maps->time - maps->m : 5;

    gm->pl->py += .2;
    player_bounce(gm, maps);
    if (gm->jumped) player_jump(gm, maps);
    sfSprite_move(gm->pl->sp[gm->pl->m], (sfVector2f){speed, gm->pl->py});
    gm->jumped = false;
    pos = sfSprite_getPosition(gm->pl->sp[gm->pl->m]);
    if (pos.x > 1920) {
        my_printf("You win :)\n");
        sfRenderWindow_close(gm->window);
    }
}
