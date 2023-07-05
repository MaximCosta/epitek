/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** tower
*/

#include "defender.h"

int check_in(game_t *game, sfVector2i p)
{
    for (int i = 0; i < game->ctower; i++) {
        if (game->towers[i]->lvl == 0)
            continue;
        if (game->towers[i]->cas.x == p.x && game->towers[i]->cas.y == p.y)
            return 1;
    }
    return 0;
}

int get_tower_lvl(game_t *game, sfVector2i p)
{
    for (int i = 0; i < game->ctower; i++) {
        if (game->towers[i]->lvl == 0)
            continue;
        if (game->towers[i]->cas.x == p.x && game->towers[i]->cas.y == p.y)
            return game->towers[i]->lvl;
    }
    return 0;
}

void set_tower_lvl(game_t *game, sfVector2i p)
{
    for (int i = 0; i < game->ctower; i++) {
        if (game->towers[i]->lvl == 0)
            continue;
        if (game->towers[i]->cas.x == p.x && game->towers[i]->cas.y == p.y) {
            apply_level(game->towers[i], game);
        }
    }
}

void init_tower(game_t *game, int choice)
{
    int i;

    if (game->price[choice][0] > game->money)
        return;
    for (i = 0; i < game->ctower; i++)
        if (game->towers[i]->lvl == 0)
            break;
    game->money -= game->price[choice][0];
    game->towers[i]->lvl = 1;
    game->towers[i]->cor.top = 0;
    game->towers[i]->dir = choice;
    game->towers[i]->clvl.left = 0;
    game->towers[i]->clvl.top = 89;
    game->towers[i]->cor.width = 89;
    game->towers[i]->cor.height = 89;
    game->towers[i]->clvl.width = 89;
    game->towers[i]->clvl.height = 89;
    game->towers[i]->cas = game->mn->mc;
    game->towers[i]->cor.left = choice * 89;
    game->towers[i]->c.x = game->mn->mc.x * game->cell + game->sx;
    game->towers[i]->c.y = game->mn->mc.y * game->cell + game->sy;
    sfMusic_play(game->mu_craft);
}

void print_tower(game_t *game)
{
    for (int i = 0; i < game->ctower; i++) {
        if (game->towers[i]->lvl == 0)
            continue;
        sfSprite_setTextureRect(game->asset->tsp, game->towers[i]->cor);
        sfSprite_setPosition(game->asset->tsp, game->towers[i]->c);
        sfRenderWindow_drawSprite(game->wd, game->asset->tsp, NULL);
        sfSprite_setTextureRect(game->asset->tsp, game->towers[i]->clvl);
        sfSprite_setPosition(game->asset->tsp, game->towers[i]->c);
        sfRenderWindow_drawSprite(game->wd, game->asset->tsp, NULL);
    }
    return;
}
