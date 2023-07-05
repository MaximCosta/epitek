/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-dante-maxim.costa
** File description:
** main
*/

#include "my.h"

void free_all(solver_t *sol)
{
    free(sol->file);
    for (int i = 0; i < sol->size.y; i++)
        free(sol->map[i]);
    free(sol->map);
    free(sol);
}

void check_loose(solver_t *sol)
{
    print_final(sol);
    free_all(sol);
    exit(0);
}

void check_win(solver_t *sol)
{
    if (sol->pos.x == sol->size.x - 1 && sol->pos.y == sol->size.y - 1) {
        sol->map[sol->pos.y][sol->pos.x] = 'o';
        print_final(sol);
        free_all(sol);
        exit(0);
    }
}

int main(int ac, char *av[])
{
    solver_t *sol = my_calloc(1, sizeof(solver_t));
    if (ac < 2)
        return 84;
    sol->pos.x = 0;
    sol->pos.y = 0;
    load_file(av[1], sol);
    while (1) {
        check_move(sol);
        move(sol, 'o');
        check_win(sol);
    }
    print_final(sol);
    return 0;
}
