/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** menu_selec
*/

#include "defender.h"

void chx_play(game_t *game)
{
    print_map(game);
    print_tower(game);
    print_mtower(game);
}

void chx_pause(game_t *game)
{
    get_pause_event(game);
    print_pause(game);
}

void chx_info(game_t *game)
{
    get_info_event(game);
    print_info(game);
}

void chx_mani(game_t *game)
{
    set_animation_menu(game);
    print_menu(game);
}

void switch_scene(game_t *game)
{
    switch (game->state) {
        case MENU:
            get_menu_event(game);
            print_menu(game);
            break;
        case MANI:
            chx_mani(game);
            break;
        case PLAY:
            chx_play(game);
            break;
        case PAUSE:
            chx_pause(game);
            break;
        case INFO:
            chx_info(game);
            break;
        case EXIT:
            break;
    }
}
