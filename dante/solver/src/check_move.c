/*
** EPITECH PROJECT, 2022
** dante [WSL: Ubuntu]
** File description:
** check_move
*/

#include "my.h"

void turn_right(solver_t *sol, char s)
{
    sol->right = false;
    if (sol->pos.x + 1 > sol->size.x)
        return;
    if (sol->map[sol->pos.y][sol->pos.x + 1] == s)
        sol->right = true;
}

void turn_left(solver_t *sol, char s)
{
    sol->left = false;
    if (sol->pos.x - 1 < 0)
        return;
    if (sol->map[sol->pos.y][sol->pos.x - 1] == s)
        sol->left = true;
}

void top(solver_t *sol, char s)
{
    sol->top = false;
    if (sol->pos.y + 1 > (sol->size.y - 1))
        return;
    if (sol->map[sol->pos.y + 1][sol->pos.x] == s)
        sol->top = true;
}

void down(solver_t *sol, char s)
{
    sol->down = false;
    if (sol->pos.y - 1 < 0)
        return;
    if (sol->map[sol->pos.y - 1][sol->pos.x] == s)
        sol->down = true;
}
