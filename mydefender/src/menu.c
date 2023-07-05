/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** menu
*/

#include "defender.h"

void print_menu(game_t *game)
{
    int cur;

    sfRenderWindow_drawSprite(game->wd, game->bsp, NULL);
    sfText_setString(game->mn->text, "MENU");
    sfText_setPosition(game->mn->text, gp(game->wx / 2 - 150, 25));
    sfRenderWindow_drawText(game->wd, game->mn->text, NULL);
    for (int i = 0; i < FMENU; i += 2) {
        cur = i + game->mn->np[i / 2];
        sfRenderWindow_drawSprite(game->wd, game->mn->sp[cur], NULL);
    }
}

void get_menu_event(game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->wd);
    sfFloatRect btn;
    int x;
    int y;

    for (int i = 0; i < FMENU; i += 2) {
        btn = sfSprite_getGlobalBounds(game->mn->sp[i]);
        x = btn.left <= pos.x && pos.x <= btn.left + btn.width;
        y = btn.top <= pos.y && pos.y <= btn.top + btn.height;
        game->mn->np[i / 2] = x && y;
    }
    if (game->mn->np[0] && game->is_press)
        game->state = MANI;
    if (game->mn->np[1] && game->is_press)
        game->state = EXIT;
}

void set_animation_menu(game_t *game)
{
    sfVector2f pos;
    sfVector2f btn;
    bool next = true;

    game->mn->np[0] = 0;
    game->mn->np[1] = 0;
    for (int i = 0; i < FMENU; i += 2) {
        pos.x = 0;
        pos.y = (game->delta * 4) * ((FMENU - i) / 2);
        sfSprite_move(game->mn->sp[i], pos);
        btn = sfSprite_getPosition(game->mn->sp[i]);
        next &= btn.y > game->wy;
    }
    if (!next)
        return;
    game->state = PLAY;
    init_play(game);
    for (int i = 0; i < FMENU; i += 2) {
        sfSprite_setPosition(game->mn->sp[i], game->mn->pos[i]);
    }
}
