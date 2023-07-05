/*
** EPITECH PROJECT, 2022
** dante [WSL: Ubuntu]
** File description:
** print_map
*/

#include "my.h"

void print_final2(solver_t *sol, int x, int y)
{
    if (sol->map[y][x] == '0') {
        printf("*");
        return;
    }
    printf("%c", sol->map[y][x]);
}

void print_final(solver_t *sol)
{
    for (int y = 0; y < sol->size.y; y++) {
        for (int x = 0; x < sol->size.x; x++) {
            print_final2(sol, x, y);
        }
        if (y != sol->size.y - 1)
            printf("\n");
    }
}
