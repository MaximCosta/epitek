/*
** EPITECH PROJECT, 2022
** duosumper05
** File description:
** check_rev
*/

#include "my.h"

int check_win_rev_diag(game_t *gm, int y, int x, char p)
{
    for (int i = 0; i < gm->size; i++) {
        if (y + i >= gm->size || x - i < 0)
            return (0);
        if (gm->board[y + i][x - i] != p)
            return (0);
    }
    return (1);
}
