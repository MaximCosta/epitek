/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** pause
*/

#include "defender.h"

void print_pause(game_t *game)
{
    int cur;

    sfText_setString(game->mn->text, "PAUSE");
    sfText_setPosition(game->mn->text, gp(game->wx / 2 - 170, 25));
    sfRenderWindow_drawText(game->wd, game->mn->text, NULL);
    for (int i = FMENU; i < FILE; i += 2) {
        cur = i + game->mn->np[i / 2];
        sfRenderWindow_drawSprite(game->wd, game->mn->sp[cur], NULL);
    }
}

void get_pause_event(game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->wd);
    sfFloatRect btn;
    int x;
    int y;

    for (int i = FMENU; i < FILE; i += 2) {
        btn = sfSprite_getGlobalBounds(game->mn->sp[i]);
        x = btn.left <= pos.x && pos.x <= btn.left + btn.width;
        y = btn.top <= pos.y && pos.y <= btn.top + btn.height;
        game->mn->np[i / 2] = x && y;
    }
    if (game->mn->np[2] && game->is_press)
        game->state = PLAY;
    if (game->mn->np[3] && game->is_press)
        game->state = MENU;
    if (game->mn->np[4] && game->is_press)
        game->state = INFO;
    if (game->mn->np[5] && game->is_press)
        game->state = EXIT;
}
