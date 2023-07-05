/*
** EPITECH PROJECT, 2022
** sokoban [WSL: Ubuntu]
** File description:
** loose
*/

#include "my.h"

bool check_space(char s)
{
    return s != ' ' && s != 'O' && s != 'X';
}

// || get_box(x, y + 1, g) != -1;
// || get_box(x, y - 1, g) != -1;
// || get_box(x + 1, y, g) != -1;
// || get_box(x - 1, y, g) != -1;
bool check_loose1(int x, int y, game_t *g)
{
    bool c = g->maps[y][x] == 'O';
    bool c1 = g->maps[y + 1][x] == '#';
    bool c2 = g->maps[y - 1][x] == '#';
    bool c3 = g->maps[y][x + 1] == '#';
    bool c4 = g->maps[y][x - 1] == '#';
    return !c && ((c1 || c2) && (c3 || c4));
}

void check_loose(game_t *game)
{
    for (int i = 0; i < game->box; i++)
        if (check_loose1(game->boxs[i], game->boys[i], game) == true)
            my_exit_ncurses(1);
}
