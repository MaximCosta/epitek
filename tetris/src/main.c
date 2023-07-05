/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-maxim.costa
** File description:
** main.c
*/

#include "../include/tetris.h"

int game(tetris_t *tetris)
{
    init_ncurses();
    load_screen_p(tetris, "./interface/part1.interface", &tetris->p1);
    load_screen_p(tetris, "./interface/part2.interface", &tetris->p2);
    load_screen_p(tetris, "./interface/part3.interface", &tetris->p3);
    init_screen(tetris);
    init_pieces(tetris);
    tetris->player = my_calloc(sizeof(player_t), 1);
    tetris->player->level = 1;
    tetris->time = clock();
    loop_game(tetris);
}

int main(int ac, char *av[])
{
    tetris_t *tetris = init_struct();

    setlocale(LC_ALL, "");
    arguments(ac, av, tetris->input);
    loader(tetris);
    if (tetris->input->help == 1)
        helper(av);
    if (tetris->input->debug == 1)
        debug_print(tetris);
    else
        game(tetris);
    free_all(tetris);
    return 0;
}
