/*
** EPITECH PROJECT, 2022
** dante [WSL: Ubuntu]
** File description:
** move
*/

#include "my.h"

void check_move(solver_t *sol)
{
    turn_right(sol, '*');
    turn_left(sol, '*');
    top(sol, '*');
    down(sol, '*');
}

void is_blocked(solver_t *sol)
{
    turn_right(sol, 'o');
    turn_left(sol, 'o');
    top(sol, 'o');
    down(sol, 'o');
    move_back(sol, '0');
}

void move(solver_t *sol, char s)
{
    sol->map[sol->pos.y][sol->pos.x] = s;
    if (sol->right == true) {
        sol->pos.x++;
        return;
    }
    if (sol->top == true) {
        sol->pos.y++;
        return;
    }
    if (sol->left == true) {
        sol->pos.x--;
        return;
    }
    if (sol->down == true) {
        sol->pos.y--;
        return;
    }
    is_blocked(sol);
}

void move_back(solver_t *sol, char s)
{
    sol->map[sol->pos.y][sol->pos.x] = s;
    if (sol->left == true) {
        sol->pos.x--;
        return;
    }
    if (sol->down == true) {
        sol->pos.y--;
        return;
    }
    if (sol->right == true) {
        sol->pos.x++;
        return;
    }
    if (sol->top == true) {
        sol->pos.y++;
        return;
    }
    check_loose(sol);
}
