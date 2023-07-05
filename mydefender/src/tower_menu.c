/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** tower_menu
*/

#include "defender.h"

void get_towopen(game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->wd);
    sfVector2f cor;

    cor.x = pos.x;
    cor.y = pos.y;
    if (game->mtower)
        return;
    pos.x = (pos.x - game->sx) / game->cell;
    pos.y = (pos.y - game->sy) / game->cell;
    if (pos.x < 0 || pos.y < 0 || pos.x >= game->lw || pos.y >= game->lh)
        return;
    if (game->maps[pos.y][pos.x] == 13 && get_tower_lvl(game, pos) < 4) {
        game->mn->mc = pos;
        cor.x = cor.x - (int) cor.x % game->cell - game->cell / 2 - 30;
        cor.y = ((pos.y + 1) * game->cell) - game->cell + game->sy - 60;
        sfSprite_setPosition(game->mn->msp, cor);
        game->mn->choice = check_in(game, pos);
        game->tower = 1;
    }
}

int get_tower(game_t *game)
{
    sfFloatRect menu = sfSprite_getGlobalBounds(game->mn->msp);
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->wd);
    bool y = true;
    bool x = true;

    if (game->tower == 0)
        return -1;
    x = menu.left <= pos.x && pos.x <= menu.left + menu.width;
    y = menu.top <= pos.y && pos.y <= menu.top + menu.height;
    if (!y || !x)
        return -1;
    if (game->mn->choice == 1) {
        set_tower_lvl(game, game->mn->mc);
        return -1;
    }
    pos.x -= menu.left;
    return pos.x / (menu.width / 4);
}

void get_towclose(game_t *game)
{
    sfFloatRect menu = sfSprite_getGlobalBounds(game->mn->msp);
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->wd);
    bool y = true;
    bool x = true;

    if (game->tower == 0)
        return;
    x = menu.left <= pos.x && pos.x <= menu.left + menu.width;
    y = menu.top <= pos.y && pos.y <= menu.top + menu.height;
    if (!y || !x)
        game->tower = 0;
}

void print_mtower(game_t *game)
{
    int choice = -1;

    if (game->is_press) {
        choice = get_tower(game);
        get_towclose(game);
        get_towopen(game);
    }
    if (choice != -1) {
        init_tower(game, choice);
        game->tower = 0;
    }
    if (!game->tower)
        return;
    choice = 47 * game->mn->choice;
    sfSprite_setTextureRect(game->mn->msp, (sfIntRect){0, choice, 129, 47});
    sfRenderWindow_drawSprite(game->wd, game->mn->msp, NULL);
}
