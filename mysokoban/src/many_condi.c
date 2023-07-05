/*
** EPITECH PROJECT, 2022
** sokoban [WSL: Ubuntu]
** File description:
** many_condi
*/

#include "my.h"

void maps_condi(game_t *game, int i, int j, int *bi)
{
    if (game->maps[i][j] == 'X') {
        game->boxs[++(*bi)] = j;
        game->boys[*bi] = i;
    }
    if (game->maps[i][j] == 'P') {
        game->px = j;
        game->py = i;
    }
}

void print_condi(game_t *game, int y)
{
    for (int x = 0; x < game->w; x++) {
        if (game->maps[y][x] == '#')
            printw("#");
        else if (game->maps[y][x] == 'O')
            printw("O");
        else
            printw(" ");
    }
}

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; 1; i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] == '\0')
            return 0;
    }
}

static int to_small(game_t *game)
{
    int y;
    int x;

    getmaxyx(stdscr, x, y);
    if (x >= game->w && y >= game->h)
        return 0;
    erase();
    mvprintw(x / 2, y / 2 - 5, "to small");
    return 1;
}

void loop_main(game_t *game, char *argv[])
{
    int res;

    move(0, 0);
    refresh();
    if (to_small(game) == 1)
        return;
    print_map(game);
    res = my_getchr(game);
    check_loose(game);
    check_win(game);
    if (res == 10)
        game = load_game(argv);
}
