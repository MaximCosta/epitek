/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** info
*/

#include "defender.h"

void print_info(game_t *game)
{
    sfText_setString(game->mn->text, "INFO");
    sfText_setPosition(game->mn->text, gp(game->wx / 2 - 170, 100));
    sfRenderWindow_drawText(game->wd, game->mn->text, NULL);
    sfRenderWindow_drawSprite(game->wd, game->mn->isp, NULL);
}

void get_info_event(game_t *game)
{
    if (game->is_press)
        game->state = PAUSE;
}
