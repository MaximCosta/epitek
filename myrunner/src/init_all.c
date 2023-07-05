/*
** EPITECH PROJECT, 2021
** test [SSH: 192.168.177.128]
** File description:
** init_all
*/

#include "game.h"
#include "my.h"
#include "my_printf.h"

void init_music(game_t *games)
{
    games->music = sfMusic_createFromFile("./assets/music/play_loop.ogg");
    play_music(games);
}

void play_music(game_t *games)
{
    sfMusic_setLoop(games->music, true);
    sfMusic_play(games->music);
}

sfRenderWindow *gw(sfVideoMode m, char *str)
{
    return sfRenderWindow_create(m, str, sfFullscreen | sfClose, NULL);
}

void init_all(game_t *games, maps_t *maps)
{
    sfVideoMode mode = {1920, 1080, 32};

    games->window = gw(mode, "runner");
    games->clock = sfClock_create();
    init_music(games);
    init_wallpaper(games);
    init_ground(games);
    init_player(games, maps);
    init_score(games);
    death_init(games);
    sfRenderWindow_setFramerateLimit(games->window, 60);
    games->pause = false;
    games->spause = 0;
    games->jumped = false;
}
