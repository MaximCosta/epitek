/*
** EPITECH PROJECT, 2022
** duostumper05
** File description:
** check_wins
*/

#include "my.h"

int check_win_line(game_t *gm, int y, int x, char p)
{
    for (int i = 0; i < gm->size; i++)
        if (x + i >= gm->size || gm->board[y][x + i] != p)
            return (0);
    return (1);
}

int check_win_hori(game_t *gm, int y, int x, char p)
{
    for (int i = 0; i < gm->size; i++)
        if (y + i >= gm->size || gm->board[y + i][x] != p)
            return (0);
    return (1);
}

int check_win_diag(game_t *gm, int y, int x, char p)
{
    for (int i = 0; i < gm->size; i++) {
        if (y + i >= gm->size || x + i >= gm->size)
            return (0);
        if (gm->board[y + i][x + i] != p)
            return (0);
    }
    return (1);
}

int check_win2(game_t *gm, int x, int y)
{
    char p = gm->board[y][x];

    if (gm->board[y][x] == '.')
        return (0);
    if (check_win_line(gm, y, x, p))
        return (1);
    if (check_win_diag(gm, y, x, p))
        return (1);
    if (check_win_rev_diag(gm, y, x, p))
        return (1);
    if (check_win_hori(gm, y, x, p))
        return (1);
    return (0);
}

int check_win(game_t *gm)
{
    int win = 0;

    for (int y = 0; y < gm->size; y++) {
        for (int x = 0; x < gm->size; x++)
            win = MAX(check_win2(gm, x, y), win);
        if (win) {
            return (1);
        }
    }
    return 0;
}
