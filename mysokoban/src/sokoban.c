/*
** EPITECH PROJECT, 2022
** sokoban [WSL: Ubuntu]
** File description:
** sokoban
*/

#include "my.h"

void my_exit_ncurses(int code)
{
    erase();
    endwin();
    exit(code);
}

int get_box(int x, int y, game_t *game)
{
    for (int i = 0; i < game->box; i++)
        if (game->boxs[i] == x && game->boys[i] == y)
            return i;
    return -1;
}

int verif_move(int x, int y, game_t *g)
{
    int b = -1;

    if (g->maps[g->py + y][g->px + x] == '#')
        return 0;
    if ((b = get_box(g->px + x, g->py + y, g)) != -1) {
        if (g->maps[g->boys[b] + y][g->boxs[b] + x] == '#')
            return 0;
        if (get_box(g->boxs[b] + x, g->boys[b] + y, g) != -1)
            return 0;
        g->boys[b] += y;
        g->boxs[b] += x;
    }
    g->py += y;
    g->px += x;
    return 1;
}

int my_getchr(game_t *game)
{
    int ch1 = getch();

    switch (ch1) {
        case KEY_LEFT: return verif_move(-1, 0, game);
        case KEY_RIGHT: return verif_move(1, 0, game);
        case KEY_UP: return verif_move(0, -1, game);
        case KEY_DOWN: return verif_move(0, 1, game);
        case 27: my_exit_ncurses(0);
        case ' ': return 10;
    }
    return -2;
}

void print_map(game_t *game)
{
    for (int y = 0; y < game->h; y++) {
        print_condi(game, y);
        printw("\n");
    }
    mvprintw(game->py, game->px, "P");
    for (int i = 0; i < game->box; i++) {
        if (game->maps[game->boys[i]][game->boxs[i]] == 'O')
            mvprintw(game->boys[i], game->boxs[i], "X");
        else
            mvprintw(game->boys[i], game->boxs[i], "X");
    }
}
