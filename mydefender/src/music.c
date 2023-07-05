/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** music
*/

#include "defender.h"

void init_music(game_t *game)
{
    game->mu_craft = sfMusic_createFromFile("./assets/sound/craft.ogg");
    game->mu_loop = sfMusic_createFromFile("./assets/sound/main_theme.ogg");
    game->mu_upgrade = sfMusic_createFromFile("./assets/sound/upgrade.ogg");
    play_music(game);
}

void play_music(game_t *game)
{
    sfMusic_setLoop(game->mu_loop, true);
    sfMusic_play(game->mu_loop);
}
